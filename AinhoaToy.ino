double distance_table[15] = {15.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 110.0, 120.0, 130.0, 140.0, 150.0};
double voltage_table[15] = {2.75, 2.52, 2.0, 1.52, 1.25, 1.1, 0.9, 0.8, 0.7, 0.65, 0.6, 0.55, 0.51, 0.48, 0.45};
boolean blinking_state = false;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  int sensorValue = analogRead(A0);
  double outputVoltage = sensorValue * 5.0 / 1023;
  double distance = 200.0;
  for (int i = 0; i < 15; i++) {
    if (outputVoltage > voltage_table[i]) {
      distance = distance_table[i];
      break;
    }
  }
  Serial.println(distance);
  if (distance < 50.0) {
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    blinking_state = false;
  }
  else if (distance > 100.0) {
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    blinking_state = false;
  }
  else {
    digitalWrite(4, blinking_state);
    digitalWrite(2, !blinking_state);
    blinking_state = !blinking_state;
  }
  delay(100);
}

#define joyX A0
#define joyY A1

#define greenLed 3
#define blueLed 5
#define yellowLed 6
#define redLed 9

unsigned int xValue = 0;
unsigned int yValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  //int light = sqrt(pow(xValue, 2) + pow(yValue, 2))/5;

  //print joystick values
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  //delayMicroseconds(50000);
  delay(50);

  if (xValue < 510 && yValue > 500 && yValue < 530) {
    analogWrite(blueLed, (510 - xValue) / 2);
    return;
  }
  if (xValue > 520 && yValue > 500 && yValue < 530) {
    analogWrite(yellowLed, (xValue - 512) / 2);
    return;
  }
  if (yValue > 520 && xValue > 500 && xValue < 530) {
    analogWrite(redLed, (yValue - 512) / 2);
    return;
  }
  if (yValue < 510 && xValue > 500 && xValue < 530) {
    analogWrite(greenLed, (510 - yValue) / 2);
    return;
  }

  //turn off all LED if joystick isn't in the correct position.
  analogWrite(blueLed, 0);
  analogWrite(yellowLed, 0);
  analogWrite(redLed, 0);
  analogWrite(greenLed, 0);
}
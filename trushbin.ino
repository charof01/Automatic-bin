#include <Servo.h>
Servo myservo;
int State = 0;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
  delay(10000);
  myservo.write(150);
}
void loop() {
  int Sr = digitalRead(2);
  Serial.println(State);
  if (State == 0) {
    if (Sr == 1) {
      myservo.write(150);
      delay(100);
    } else if (Sr == 0) {
      myservo.write(0);
      State = 1;
    }
  }
  if (State == 1) {
    delay(3000);
    State = 0;
  }
}

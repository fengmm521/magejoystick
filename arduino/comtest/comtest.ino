/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#define D8 8
#define DInput 7
//#define D9 9
#define LEFT 12
#define RIGHT 11
#define ATTACK 10
#define JUMP 9
#define FIRE 8
const int buttonPin=2; //开关引脚为2

const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //  Serial.end();
  delay(100);
  pinMode(ledPin, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(ATTACK, OUTPUT);
  pinMode(JUMP, OUTPUT);
  pinMode(FIRE, OUTPUT);
  
  Serial.begin(115200);
  delay(1);
  digitalWrite(ledPin, HIGH);
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  digitalWrite(ATTACK, LOW);
  digitalWrite(JUMP, LOW);
  digitalWrite(FIRE, LOW);
}

// the loop function runs over and over again forever

int isOpen = false;

void loop() {
//  int input = digitalRead(DInput);
  
  if (Serial.available() > 0) {
    delay(5); // 等待数据传完
//    int numdata = Serial.available();
//    Serial.print("Serial.available = :");
    char tmp = Serial.read();
    delay(3);
    Serial.write(tmp);
    delay(3);
  }
 
  if (isOpen) {
    delay(1);
    digitalWrite(ledPin, HIGH);
    delay(1);

  } else {
    
    delay(1);
    digitalWrite(ledPin, LOW);
    delay(1);

  }
}

/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  Gamepad example
  Press a button and demonstrate Gamepad actions

  You can also use Gamepad1,2,3 and 4 as single report.
  This will use 1 endpoint for each gamepad.

  See HID Project documentation for more infos
  https://github.com/NicoHood/HID/wiki/Gamepad-API
*/

#include "HID-Project.h"
//https://github.com/NicoHood/HID

/*
 *                    S1(D14)   S2(D15)  
 *       A0                                                       /
 *                    5(D2)   6(D4)   7(D6)   8(D8)              /    C1(D10) 
 *   A3       A1                                                / 
 *                    1(D3)   2(D5)   3(D7)   4(D9)            /    RESET
 *       A2                                                   /
 *                                                           /
 */

const int btn1 = 3;
const int btn2 = 5;
const int btn3 = 7;
const int btn4 = 9;
const int btn5 = 2;
const int btn6 = 4;
const int btn7 = 6;
const int btn8 = 8;
const int btnS1 = 14;
const int btnS2 = 15;

const int btnC1 = 10;
const int btnC2 = 16;

const int bUp = A0;
const int bRight = A1;
const int bDown = A2;
const int bLeft = A3;



void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(btn5, INPUT_PULLUP);
  pinMode(btn6, INPUT_PULLUP);
  pinMode(btn7, INPUT_PULLUP);
  pinMode(btn8, INPUT_PULLUP);
  pinMode(btnS1, INPUT_PULLUP);
  pinMode(btnS2, INPUT_PULLUP);
  pinMode(btnC1, INPUT_PULLUP);
  pinMode(btnC2, INPUT_PULLUP);
  
  pinMode(bUp, INPUT_PULLUP);
  pinMode(bRight, INPUT_PULLUP);
  pinMode(bDown, INPUT_PULLUP);
  pinMode(bLeft, INPUT_PULLUP);

  // Sends a clean report to the host. This is important on any Arduino type.
  Gamepad.begin();
}

bool isRightYG = false;



void loop() {

  if (!digitalRead(btn1)) {
    Gamepad.press(1);
  }else{
    Gamepad.release(1);
  }
  if (!digitalRead(btn2)) {
    Gamepad.press(2);
  }
  else{
    Gamepad.release(2);
  }
  if (!digitalRead(btn3)) {
    Gamepad.press(3);
  }else{
    Gamepad.release(3);
  }
  if (!digitalRead(btn4)) {
      isRightYG = true;
  }else{
      isRightYG = false;
  }
  if (!digitalRead(btn5)) {
    Gamepad.press(5);
  }else{
    Gamepad.release(5);
  }
  if (!digitalRead(btn6)) {
    Gamepad.press(6);
  }else{
    Gamepad.release(6);
  }
  if (!digitalRead(btn7)) {
    Gamepad.press(7);
  }else{
    Gamepad.release(7);
  }
  if (!digitalRead(btn8)) {
    Gamepad.press(8);
  }else{
    Gamepad.release(8);
  }
  // bool btnS1_state_now = false;
  // bool btnS2_state_now = false;
  // bool btnC1_state_now = false;
  // bool btnC2_state_now = false;
  if (!digitalRead(btnS1)) {
    Gamepad.press(9);
  }else{
    Gamepad.release(9);
  }

  if (!digitalRead(btnS2)) {
    Gamepad.press(10);
  }else{
    Gamepad.release(10);
  }

  if (!digitalRead(btnC1)) {
    Gamepad.press(11);
  }else{
    Gamepad.release(11);
  }
  if (!digitalRead(btnC2)) {
    Gamepad.press(12);
  }else{
    Gamepad.release(12);
  }

  //u=d
  //d=l
  //l=u
  //r=r
  bool isup = !digitalRead(bLeft);
  bool isright = !digitalRead(bRight);
  bool isdown = !digitalRead(bUp);
  bool isleft = !digitalRead(bDown);

  
//  bool isleft = !digitalRead(bLeft);
//  bool isright = !digitalRead(bRight);
//  bool isup = !digitalRead(bUp);
//  bool isdown = !digitalRead(bDown);
  if(isRightYG){
        if (isleft || isright) {
          if(isleft){
            Gamepad.rxAxis(-32760);
          }else{
              Gamepad.rxAxis(32760);
            }
        }else{
          Gamepad.rxAxis(0);
          Gamepad.xAxis(0);

        }
        if (isup || isdown) {
          if(isdown){
            Gamepad.ryAxis(-32760);
          }else{
              Gamepad.ryAxis(32760);
            }
        }else{
          Gamepad.ryAxis(0);
          Gamepad.yAxis(0);
        }
    }else{
        if (isleft || isright) {
          if(isleft){
            Gamepad.xAxis(-32760);
          }else{
              Gamepad.xAxis(32760);
            }
        }else{
          Gamepad.rxAxis(0);
          Gamepad.xAxis(0);
        }
        if (isup || isdown) {
          if(isdown){
            Gamepad.yAxis(-32760);
          }else{
              Gamepad.yAxis(32760);
            }
        }else{
          Gamepad.yAxis(0);
          Gamepad.ryAxis(0);
        }
    }

  Gamepad.write();

  delay(20);
}

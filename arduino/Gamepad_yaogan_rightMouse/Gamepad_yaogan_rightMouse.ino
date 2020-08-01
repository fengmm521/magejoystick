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
 *                    1(D3)   2(D5)   3(D7)   4(D9)            /    c2(D16)
 *       A2                                                   /
 *                                                           /
 */

const int btn1 = 3;
const int btn2 = 5;
const int btn3 = 7;
const int MouseRight = 9;
const int btn5 = 2;
const int btn6 = 4;
const int btn7 = 6;
const int MouseLeft = 8;
const int btnS1 = 14;
const int btnS2 = 15;

const int btnC1 = 10;
const int btnC2 = 16;

const int bUp = A0;
const int bRight = A1;
const int bDown = A2;
const int bLeft = A3;

uint32_t lastState = 0;

bool isMouseRightUse = false;
bool isMouseLeftUse = false;

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(MouseRight, INPUT_PULLUP);
  pinMode(btn5, INPUT_PULLUP);
  pinMode(btn6, INPUT_PULLUP);
  pinMode(btn7, INPUT_PULLUP);
  pinMode(MouseLeft, INPUT_PULLUP);
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

void loop() {
  uint32_t nowState = 0x00;
  if (!digitalRead(btn1)) {
    Gamepad.press(1);
    nowState |= (uint32_t)1 << 1; 
  }else{
    Gamepad.release(1);
    nowState &= ~((uint32_t)1 << 1); 
  }
  if (!digitalRead(btn2)) {
    Gamepad.press(2);
    nowState |= (uint32_t)1 << 2; 
  }
  else{
    Gamepad.release(2);
    nowState &= ~((uint32_t)1 << 2); 
  }
  if (!digitalRead(btn3)) {
    Gamepad.press(3);
    nowState |= (uint32_t)1 << 3; 
  }else{
    Gamepad.release(3);
    nowState &= ~((uint32_t)1 << 3);
  }
  if (!digitalRead(MouseRight)) {
//    Gamepad.press(4);
//    nowState |= (uint32_t)1 << 4; 
    isMouseRightUse = true;
  }else{
//    Gamepad.release(4);
//    nowState &= ~((uint32_t)1 << 4);
    isMouseRightUse = false;
  }
  if (!digitalRead(btn5)) {
    Gamepad.press(5);
    nowState |= (uint32_t)1 << 5; 
  }else{
    Gamepad.release(5);
    nowState &= ~((uint32_t)1 << 5);
  }
  if (!digitalRead(btn6)) {
    Gamepad.press(6);
    nowState |= (uint32_t)1 << 6; 
  }else{
    Gamepad.release(6);
    nowState &= ~((uint32_t)1 << 6);
  }
  if (!digitalRead(btn7)) {
    Gamepad.press(7);
    nowState |= (uint32_t)1 << 7; 
  }else{
    Gamepad.release(7);
    nowState &= ~((uint32_t)1 << 7);
  }
  if (!digitalRead(MouseLeft)) {
    Gamepad.press(8);
    nowState |= (uint32_t)1 << 8; 
//    isMouseLeftUse = true;
  }else{
    Gamepad.release(8);
    nowState &= ~((uint32_t)1 << 8);
//    isMouseLeftUse = false;
  }

  if (!digitalRead(btnS1)) {
    Gamepad.press(9);
    nowState |= (uint32_t)1 << 9; 
  }else{
    Gamepad.release(9);
    nowState &= ~((uint32_t)1 << 9);
  }

  if (!digitalRead(btnS2)) {
    Gamepad.press(10);
    nowState |= (uint32_t)1 << 10; 
  }else{
    Gamepad.release(10);
    nowState &= ~((uint32_t)1 << 10);
  }

  if (!digitalRead(btnC1)) {
    Gamepad.press(11);
    nowState |= (uint32_t)1 << 11; 
  }else{
    Gamepad.release(11);
    nowState &= ~((uint32_t)1 << 11);
  }
  if (!digitalRead(btnC2)) {
    Gamepad.press(12);
    nowState |= (uint32_t)1 << 16; 
  }else{
    Gamepad.release(12);
    nowState &= ~((uint32_t)1 << 16);
  }

  //u=d
  //d=l
  //l=u
  //r=r
//  bool isup = !digitalRead(bLeft);
//  bool isright = !digitalRead(bRight);
//  bool isdown = !digitalRead(bUp);
//  bool isleft = !digitalRead(bDown);

  
  bool isleft = !digitalRead(bLeft);
  bool isright = !digitalRead(bRight);
  bool isup = !digitalRead(bUp);
  bool isdown = !digitalRead(bDown);
  if (isleft || isright) {
    if(isleft){
        if(isMouseRightUse){
          Gamepad.rxAxis(-32760);
        }else{
          Gamepad.xAxis(-32760);
        }
      
        nowState |= (uint32_t)1 << 12; 
    }else{
          if(isMouseRightUse){
            Gamepad.rxAxis(32760);
          }else{
            Gamepad.xAxis(32760);
          }
        nowState |= (uint32_t)1 << 13; 
      }
  }else{
    Gamepad.xAxis(0);
    Gamepad.rxAxis(0);
    nowState &= ~((uint32_t)1 << 12);
    nowState &= ~((uint32_t)1 << 13);
  }
  if (isup || isdown) {
    if(isdown){
        if(isMouseRightUse){
          Gamepad.ryAxis(-32760);
        }else{
          Gamepad.yAxis(-32760);
        }
      
      nowState |= (uint32_t)1 << 14; 
    }else{
        if(isMouseRightUse){
            Gamepad.ryAxis(32760);
          }else{
            Gamepad.yAxis(32760);
          }
        
        nowState |= (uint32_t)1 << 15; 
      }
  }else{
    Gamepad.yAxis(0);
    Gamepad.ryAxis(0);
    nowState &= ~((uint32_t)1 << 14);
    nowState &= ~((uint32_t)1 << 15);
  }

  if(lastState != nowState){

    Gamepad.write();

    // Simple debounce
    
    lastState = nowState;
  }
  delay(15);
}

/*!
 * @file  buttonInterrupt.ino
 * @brief  按键中断例程
 * @details  RGB灯循环切换红绿蓝三色，按键按下后亮白色。
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license  The MIT License (MIT)
 * @author  [qsjhyy](yihuan.huang@dfrobot.com)
 * @version  V1.0
 * @date  2022-05-17
 * @url  https://github.com/DFRobot/DFRobot_RGBButton
 */
#include <DFRobot_RGBButton.h>


/**
 * Instantiate an object to drive our sensor;
 * Set address according to encoder DIP switch
 * (the setting takes effect after encoder power fail and restart):
 * | A2 | A1 | A0 | ADDR |
 * |----|----|----|------|
 * | 0  | 0  | 0  | 0x23 |
 * | 0  | 0  | 1  | 0x24 |
 * | 0  | 1  | 0  | 0x25 |
 * | 0  | 1  | 1  | 0x26 |
 * | 1  | 0  | 0  | 0x27 |
 * | 1  | 0  | 1  | 0x28 |
 * | 1  | 1  | 0  | 0x29 |
 * | 1  | 1  | 1  | 0x2A |
 */
DFRobot_RGBButton RGBButton(&Wire, /*I2CAddr*/ 0x2A);


/* Interrupt flag */
volatile uint8_t flag = 0, temp = 0;
/* External interrupt flag */
void interrupt()
{
  if(3 != flag) {
    temp = flag;
    flag = 3;
  } else {
    flag = temp;
    temp = 4;
  }
}

void setup(void)
{
  Serial.begin(115200);

  /**
   * @brief Init function
   * @return bool type, true if successful, false if error
   */
  while( ! RGBButton.begin() ){
    Serial.println("Communication with device failed, please check connection!");
    delay(3000);
  }
  Serial.println("Begin ok!\n");

  #if defined(ESP32) || defined(ESP8266)
    // D4 pin is used as interrupt pin by default, other non-conflicting pins can also be selected as external interrupt pins.
    attachInterrupt(digitalPinToInterrupt(D4)/* Query the interrupt number of the D4 pin */, interrupt, CHANGE);
  #elif defined(ARDUINO_SAM_ZERO)
    // Pin 5 is used as interrupt pin by default, other non-conflicting pins can also be selected as external interrupt pins
    attachInterrupt(digitalPinToInterrupt(5)/* Query the interrupt number of the 5 pin */, interrupt, CHANGE);
  #else
    /* The Correspondence Table of AVR Series Arduino Interrupt Pins And Terminal Numbers
     * ---------------------------------------------------------------------------------------
     * |                                        |  DigitalPin  | 2  | 3  |                   |
     * |    Uno, Nano, Mini, other 328-based    |--------------------------------------------|
     * |                                        | Interrupt No | 0  | 1  |                   |
     * |-------------------------------------------------------------------------------------|
     * |                                        |    Pin       | 2  | 3  | 21 | 20 | 19 | 18 |
     * |               Mega2560                 |--------------------------------------------|
     * |                                        | Interrupt No | 0  | 1  | 2  | 3  | 4  | 5  |
     * |-------------------------------------------------------------------------------------|
     * |                                        |    Pin       | 3  | 2  | 0  | 1  | 7  |    |
     * |    Leonardo, other 32u4-based          |--------------------------------------------|
     * |                                        | Interrupt No | 0  | 1  | 2  | 3  | 4  |    |
     * ---------------------------------------------------------------------------------------
     * ---------------------------------------------------------------------------------------------------------------------------------------------
     * |                    The Correspondence Table of micro:bit Interrupt Pins And Terminal Numbers                                              |
     * ---------------------------------------------------------------------------------------------------------------------------------------------
     * |             micro:bit                       | DigitalPin |P0-P20 can be used as an external interrupt                                     |
     * |  (When using as an external interrupt,      |---------------------------------------------------------------------------------------------|
     * |no need to set it to input mode with pinMode)|Interrupt No|Interrupt number is a pin digital value, such as P0 interrupt number 0, P1 is 1 |
     * ---------------------------------------------------------------------------------------------------------------------------------------------
     */
    #if defined(ARDUINO_AVR_LEONARDO)
      attachInterrupt(/*Interrupt No*/4, interrupt, CHANGE);   // Leonardo的I2C引脚为2（SDA）和3（SCL），所以不能使用0,1两号中断。本示例使用4号中断，引脚为Leonardo(7)
    #else
      attachInterrupt(/*Interrupt No*/0, interrupt, CHANGE);   // Open the external interrupt 0, connect INT to the digital pin of the main control: 
                                                             // UNO(2), Mega2560(2), microbit(P0).
    #endif
  #endif
}

DFRobot_RGBButton::eGeneralRGBValue_t colorBuf[4] = {RGBButton.eRed, RGBButton.eGreen, RGBButton.eBlue, RGBButton.eWhite};

void loop()
{
  /**
   * @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
   * @param color - 七种基础颜色以及白黑(白黑对应亮灭)对应的值: 
   * @n  eRed, eOrange, eYellow, eGreen, eCyan, eBlue, ePurple, eWhite, eBlack
   * @return None
   */
  RGBButton.setRGBColor(colorBuf[flag]);

  // 闪烁延时，增大count的值从而增加闪烁间隔
  size_t count = 1600;
  for (size_t i = 0; i < count; i++) {
    for (size_t j = 0; j < count; j++) {
      if (3 == flag) {   // 当按键按下，中断产生，设置为白色
        RGBButton.setRGBColor(colorBuf[flag]);
      }
      if (4 == temp) {   // 当按键释放，中断产生，设置回按下之前的颜色
        temp = 0;
        RGBButton.setRGBColor(colorBuf[flag]);
      }
    }
  }

  // RGB灯循环切换红绿蓝三色
  if(2 > flag) {
    flag += 1;
  } else if (2 == flag) {
    flag = 0;
  }
}

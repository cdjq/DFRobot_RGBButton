/*!
 * @file  buttonCascade.ino
 * @brief  按钮模块级联功能演示
 * @details  3个按钮模块I2C级联，默认情况下三个亮白色，按下按钮后，对应的按钮变为红色、绿色、蓝色。
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
DFRobot_RGBButton RGBButton1(&Wire, /*I2CAddr*/ 0x23);   // 按钮1
DFRobot_RGBButton RGBButton2(&Wire, /*I2CAddr*/ 0x24);   // 按钮2
DFRobot_RGBButton RGBButton3(&Wire, /*I2CAddr*/ 0x25);   // 按钮3


void setup(void)
{
  Serial.begin(115200);

  // Init the sensor
  while( ! RGBButton1.begin() ){
    Serial.println("Communication with device failed, please check connection!");
    delay(3000);
  }
  while( ! RGBButton2.begin() ){
    Serial.println("Communication with device failed, please check connection!");
    delay(3000);
  }
  while( ! RGBButton3.begin() ){
    Serial.println("Communication with device failed, please check connection!");
    delay(3000);
  }
  Serial.println("Begin ok!\n");

  /**
   * @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
   * @param color - 七种基础颜色以及白黑(白黑对应亮灭)对应的值: 
   * @n  eRed, eOrange, eYellow, eGreen, eCyan, eBlue, ePurple, eWhite, eBlack
   * @return None
   */
  RGBButton1.setRGBByGeneral(RGBButton1.eWhite);
  RGBButton2.setRGBByGeneral(RGBButton2.eWhite);
  RGBButton3.setRGBByGeneral(RGBButton3.eWhite);
}

uint8_t flag1 = 0, flag2 = 0, flag3 = 0;

void loop()
{
  /**
   * @brief 获取模块按键状态
   * @return 模块当前的按键状态:
   * @n        true - 按键按下
   * @n        false - 按键未按下
   */
  if( RGBButton1.getButtonStatus() ) {   // 按键1, 按下亮红色
    flag1 = 1;
    Serial.println("Button1 press!");
    RGBButton1.setRGBByGeneral(RGBButton1.eRed);
    delay(50);
  } else if( 1 == flag1 ) {
    flag1 = 0;
    Serial.println("Button1 release!");
    RGBButton1.setRGBByGeneral(RGBButton1.eWhite);
  }

  if( RGBButton2.getButtonStatus() ) {   // 按键2, 按下亮绿色
    flag2 = 1;
    Serial.println("Button2 press!");
    RGBButton2.setRGBByGeneral(RGBButton2.eGreen);
    delay(50);
  } else if( 1 == flag2 ) {
    flag2 = 0;
    Serial.println("Button2 release!");
    RGBButton2.setRGBByGeneral(RGBButton2.eWhite);
  }

  if( RGBButton3.getButtonStatus() ) {   // 按键3, 按下亮蓝色
    flag3 = 1;
    Serial.println("Button3 press!");
    RGBButton3.setRGBByGeneral(RGBButton3.eBlue);
    delay(50);
  } else if( 1 == flag3 ) {
    flag3 = 0;
    Serial.println("Button3 release!");
    RGBButton3.setRGBByGeneral(RGBButton3.eWhite);
  }
}

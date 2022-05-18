/*!
 * @file  getButtonStatus.ino
 * @brief  按键功能演示
 * @details  按键按下亮红灯， 松开灭灯
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


void setup(void)
{
  Serial.begin(115200);

  // Init the sensor
  while( ! RGBButton.begin() ){
    Serial.println("Communication with device failed, please check connection!!!");
    delay(3000);
  }
  Serial.println("Begin ok!\n");

}

uint8_t flag = 0;

void loop()
{
  /**
   * @brief 获取模块按键状态
   * @return 模块当前的按键状态:
   * @n        true - 按键按下
   * @n        false - 按键未按下
   */
  if( RGBButton.getButtonStatus() ) {
    flag = 1;
    Serial.println("Button press!");
    /**
     * @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
     * @param color - 七种基础颜色以及白黑(白黑对应亮灭)对应的值: 
     * @n  eRed, eOrange, eYellow, eGreen, eCyan, eBlue, ePurple, eWhite, eBlack
     * @return None
     */
    RGBButton.setRGBByGeneral(RGBButton.eRed);
    delay(50);
  } else if( 1 == flag ) {
    flag = 0;
    Serial.println("Button release!");
    RGBButton.setRGBByGeneral(RGBButton.eBlack);   // 按键释放后灭灯
  }
}

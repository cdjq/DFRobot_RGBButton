/*!
 * @file  breatheLight.ino
 * @brief  呼吸灯功能演示
 * @details  按键RGB灯呈现彩色呼吸灯闪烁, 按键按下则变为红色
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
    Serial.println("Communication with device failed, please check connection!");
    delay(3000);
  }
  Serial.println("Begin ok!\n");
}

int t = 0;   // rgb值的基础变换量
uint8_t rValue = 0, gValue = 0, bValue = 0;

void loop()
{
  /**
   * @brief 获取模块按键状态
   * @return 模块当前的按键状态:
   * @n        true - 按键按下
   * @n        false - 按键未按下
   */
  if( RGBButton.getButtonStatus() ) {
    Serial.println("Button press!");
    /**
     * @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
     * @param color - 七种基础颜色以及白黑(白黑对应亮灭)对应的值: 
     * @n  eRed, eOrange, eYellow, eGreen, eCyan, eBlue, ePurple, eWhite, eBlack
     * @return None
     */
    RGBButton.setRGBByGeneral(RGBButton.eRed);
    delay(100);
  } else {
    rValue = (abs(sin(3.14 * t / 180))) * 255;
    gValue = (abs(sin(3.14 * (t + 60) / 180))) * 255;
    bValue = (abs(sin(3.14 * (t + 120) / 180))) * 255;
    t += 1;
    /**
     * @brief 用RGB值设置对应颜色
     * @param r - 红灯的脉宽值
     * @param g - 绿灯的脉宽值
     * @param b - 蓝灯的脉宽值
     * @return None
     */
    RGBButton.setRGBByValue(/*r=*/rValue, /*g=*/gValue, /*b=*/bValue);
    delay(100);
  }
}

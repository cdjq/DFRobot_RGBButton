# DFRobot_RGBButton
* [中文版](./README_CN.md)

RGB 按钮模块，一个带有rgb灯的漂亮彩色按钮。可以通过i2c设置RGB灯颜色和读取其按键状态，也可以直接通过中断引脚获取按键状态，地址拨码开关的存在，使得多个按钮可以级联。

![产品实物图](./resources/images/RGBButton.png)


## Product Link (https://www.dfrobot.com/)
    SKU: DFR0991


## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


## Summary

* 系统自定义七种颜色，红橙黄绿青蓝紫；用户也可用rgb值自定义颜色
* 用户可根据配置PWM信号控制RGB灯的亮度，独立配置周期和脉宽
* I2C地址可根据拨码开关来设置
* 按键具有中断通知功能，正常状态为低电平，按键按下为高电平


## Installation

There two methods:

1. To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.
2. Search the DFRobot_RGBButton library from the Arduino Software Library Manager and download it.


## Methods

```C++

  /**
   * @fn DFRobot_RGBButton
   * @brief Constructor
   * @param pWire - Wire object is defined in Wire.h, so just use &Wire and the methods in Wire can be pointed to and used
   * @param i2cAddr - RGBButton I2C address.
   * @return None
   */
  DFRobot_RGBButton(TwoWire *pWire=&Wire, uint8_t i2cAddr=RGBBUTTON_DEFAULT_I2C_ADDR);

  /**
   * @fn begin
   * @brief Init function
   * @return bool type, true if successful, false if error
   */
  bool begin(void);

  /**
   * @fn setRGBColor
   * @brief 设置七种基础颜色以及白黑(白黑对应亮灭)或者用RGB值设置对应颜色
   * @param color - 七种基础颜色以及白黑对应的值: 
   * @n  eRed, eOrange, eYellow, eGreen, eCyan, eBlue, ePurple, eWhite, eBlack
   * @param r - 红灯的脉宽值
   * @param g - 绿灯的脉宽值
   * @param b - 蓝灯的脉宽值
   * @return None
   */
  void setRGBColor(eGeneralRGBValue_t color);
  void setRGBColor(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn getButtonStatus
   * @brief 获取模块按键状态
   * @return 模块当前的按键状态:
   * @retval   true - 按键按下
   * @retval   false - 按键未按下
   */
  bool getButtonStatus(void);

```


## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | :----:
Arduino Uno        |      √       |              |             |
Arduino MEGA2560   |      √       |              |             |
Arduino Leonardo   |      √       |              |             |
FireBeetle-ESP8266 |      √       |              |             |
FireBeetle-ESP32   |      √       |              |             |
FireBeetle-M0      |      √       |              |             |
Micro:bit          |      √       |              |             |


## History

- 2022/05/17 - Version 1.0.0 released.


## Credits

Written by qsjhyy(yihuan.huang@dfrobot.com), 2022. (Welcome to our [website](https://www.dfrobot.com/))


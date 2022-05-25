# DFRobot_RGBButton
* [中文版](./README_CN.md)


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

* 


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
   * @fn setRGBGeneralColor
   * @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
   * @param color - 七种基础颜色以及白黑对应的值: 
   * @n  eRed, eOrange, eYellow, eGreen, eCyan, eBlue, ePurple, eWhite, eBlack
   * @return None
   */
  void setRGBGeneralColor(eGeneralRGBValue_t color);

  /**
   * @fn setRGBByValue
   * @brief 用RGB值设置对应颜色
   * @param r - 红灯的脉宽值
   * @param g - 绿灯的脉宽值
   * @param b - 蓝灯的脉宽值
   * @return None
   */
  void setRGBByValue(uint8_t r, uint8_t g, uint8_t b);

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


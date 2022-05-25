# DFRobot_RGBButton
* [中文版](./README_CN.md)

RGB 按钮模块，一个带有rgb灯的漂亮彩色按钮。可以通过i2c设置RGB灯颜色和读取其按键状态，也可以直接通过中断引脚获取按键状态，地址拨码开关的存在，使得多个按钮可以级联。

![产品实物图](../../resources/images/RGBButton.png)


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

To use the library, first download the library file, paste it into the directory you specified, then open the Examples folder and run the demo in that folder.


## Methods

```python

    '''!
      @brief Initialize sensor
      @return  Return init status
      @retval True indicate initialization succeed
      @retval False indicate initialization failed
    '''
    def begin(self):

    '''!
      @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
      @param color - 七种基础颜色以及白黑对应的值: 
      @n  e_red, e_orange, e_yellow, e_green, e_cyan, e_blue, e_purple, e_white, e_black
    '''
    def set_RGB_by_general(self, color):

    '''!
      @brief 用RGB值设置对应颜色
      @param r - 红灯的脉宽值
      @param g - 绿灯的脉宽值
      @param b - 蓝灯的脉宽值
    '''
    def set_RGB_by_value(self, r, g, b):

    '''!
      @brief 获取模块按键状态
      @return 模块当前的按键状态:
      @retval   true - 按键按下
      @retval   false - 按键未按下
    '''
    def get_button_status(self):

```


## Compatibility

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |           |            |    √     |         |
| RaspberryPi4 |     √     |            |          |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |


## History

- 2022/05/17 - Version 1.0.0 released.


## Credits

Written by qsjhyy(yihuan.huang@dfrobot.com), 2022. (Welcome to our [website](https://www.dfrobot.com/))


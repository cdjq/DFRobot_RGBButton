# -*- coding: utf-8 -*
'''!
  @file  button_cascade.py
  @brief  按钮模块级联功能演示
  @details  3个按钮模块I2C级联，默认情况下三个亮白色，按下按钮后，对应的按钮变为红色、绿色、蓝色。
  @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license  The MIT License (MIT)
  @author  [qsjhyy](yihuan.huang@dfrobot.com)
  @version  V1.0
  @date  2022-05-17
  @url  https://github.com/DFRobot/DFRobot_RGBButton
'''
from __future__ import print_function
import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))

from DFRobot_RGBButton import *

'''
  # Instantiate an object to drive our sensor;
  # Set address according to encoder DIP switch
  # (the setting takes effect after encoder power fail and restart):
  # | A2 | A1 | A0 | ADDR |
  # |----|----|----|------|
  # | 0  | 0  | 0  | 0x23 |
  # | 0  | 0  | 1  | 0x24 |
  # | 0  | 1  | 0  | 0x25 |
  # | 0  | 1  | 1  | 0x26 |
  # | 1  | 0  | 0  | 0x27 |
  # | 1  | 0  | 1  | 0x28 |
  # | 1  | 1  | 0  | 0x29 |
  # | 1  | 1  | 1  | 0x2A |
'''
RGBButton1 = DFRobot_RGBButton(i2c_addr = 0x23, bus = 1)
RGBButton2 = DFRobot_RGBButton(i2c_addr = 0x24, bus = 1)
RGBButton3 = DFRobot_RGBButton(i2c_addr = 0x25, bus = 1)


def setup():
  while not RGBButton1.begin() :
    print ('Please check that the device is properly connected!!!')
    time.sleep(3)
  while not RGBButton2.begin() :
    print ('Please check that the device is properly connected!!!')
    time.sleep(3)
  while not RGBButton3.begin() :
    print ('Please check that the device is properly connected!!!')
    time.sleep(3)
  print("RGBButton begin successfully!\n")

  '''
    # @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
    # @param color - 七种基础颜色以及白黑对应的值: 
    # @n  e_red, e_orange, e_yellow, e_green, e_cyan, e_blue, e_purple, e_white, e_black
  '''
  RGBButton1.set_RGB_by_general(RGBButton1.e_white)
  RGBButton2.set_RGB_by_general(RGBButton2.e_white)
  RGBButton3.set_RGB_by_general(RGBButton3.e_white)


def loop():
  global flag1, flag2, flag3
  '''
    # @brief 获取模块按键状态
    # @return 模块当前的按键状态:
    # @retval   true - 按键按下
    # @retval   false - 按键未按下
  '''
  if RGBButton1.get_button_status() :   # 按键1, 按下亮红色
    flag1 = 1
    print("Button1 press!")
    RGBButton1.set_RGB_by_general(RGBButton1.e_red)
    time.sleep(0.05)
  elif 1 == flag1  :
    flag1 = 0
    print("Button1 release!")
    RGBButton1.set_RGB_by_general(RGBButton1.e_white)

  if RGBButton2.get_button_status() :   # 按键2, 按下亮绿色
    flag2 = 1
    print("Button2 press!")
    RGBButton2.set_RGB_by_general(RGBButton2.e_green)
    time.sleep(0.05)
  elif 1 == flag2  :
    flag2 = 0
    print("Button2 release!")
    RGBButton2.set_RGB_by_general(RGBButton2.e_white)

  if RGBButton3.get_button_status() :   # 按键3, 按下亮蓝色
    flag3 = 1
    print("Button3 press!")
    RGBButton3.set_RGB_by_general(RGBButton3.e_blue)
    time.sleep(0.05)
  elif 1 == flag3  :
    flag3 = 0
    print("Button3 release!")
    RGBButton3.set_RGB_by_general(RGBButton3.e_white)


if __name__ == "__main__":
  global flag1, flag2, flag3
  flag1, flag2, flag3 = 0, 0, 0
  setup()
  while True:
    loop()

# -*- coding: utf-8 -*
'''!
  @file  breathe_light.py
  @brief  呼吸灯功能演示
  @details  按键RGB灯呈现彩色呼吸灯闪烁, 按键按下则变为红色
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

from math import sin
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
RGBButton = DFRobot_RGBButton(i2c_addr = 0x2A, bus = 1)


def setup():
  while not RGBButton.begin() :
    print ('Please check that the device is properly connected!!!')
    time.sleep(3)
  print("RGBButton begin successfully!\n")


def loop():
  global t, r_value, g_value, b_value
  '''
    # @brief 获取模块按键状态
    # @return 模块当前的按键状态:
    # @n        true - 按键按下
    # @n        false - 按键未按下
  '''
  if RGBButton.get_button_status() :
    print("Button press!")

    '''
      # @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
      # @param color - 七种基础颜色以及白黑对应的值: 
      # @n  e_red, e_orange, e_yellow, e_green, e_cyan, e_blue, e_purple, e_white, e_black
    '''
    RGBButton.set_RGB_by_general(RGBButton.e_red)

    time.sleep(0.1)
  else :
    r_value = int((abs(sin(3.14 * t / 180))) * 255)
    g_value = int((abs(sin(3.14 * (t + 60) / 180))) * 255)
    b_value = int((abs(sin(3.14 * (t + 120) / 180))) * 255)
    t += 1

    '''
      # @brief 用RGB值设置对应颜色
      # @param r - 红灯的脉宽值
      # @param g - 绿灯的脉宽值
      # @param b - 蓝灯的脉宽值
    '''
    RGBButton.set_RGB_by_value(r=r_value, g=g_value, b=b_value)

    time.sleep(0.1)


if __name__ == "__main__":
  global t, r_value, g_value, b_value
  t = 0   # rgb值的基础变换量
  r_value, g_value, b_value = 0, 0, 0
  setup()
  while True:
    loop()

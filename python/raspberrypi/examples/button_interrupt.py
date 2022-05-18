# -*- coding: utf-8 -*
'''!
  @file  button_interrupt.py
  @brief  按键中断例程
  @details  RGB灯循环切换红绿蓝三色, 按键按下后亮白色
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

import RPi.GPIO as GPIO
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

def int_callback(channel):
  global flag, temp
  if 3 != flag :
    temp = flag
    flag = 3
  else :
    flag = temp
  # print(flag)


def setup():
  while not RGBButton.begin() :
    print ('Please check that the device is properly connected')
    time.sleep(3)
  print("sensor begin successfully!!!")

  # Use GPIO port to monitor sensor interrupt
  gpio_int = 27
  GPIO.setwarnings(False)
  GPIO.setmode(GPIO.BCM)
  GPIO.setup(gpio_int, GPIO.IN)
  GPIO.add_event_detect(gpio_int, GPIO.BOTH, callback=int_callback, bouncetime = 30)


def loop():
  global flag

  '''
    # @brief 设置七种基础颜色以及白黑(白黑对应亮灭)
    # @param color - 七种基础颜色以及白黑对应的值: 
    # @n  e_red, e_orange, e_yellow, e_green, e_cyan, e_blue, e_purple, e_white, e_black
  '''
  RGBButton.set_RGB_by_general(color_buf[flag])

  if 2 > flag :
    flag += 1
  elif 2 == flag :
    flag = 0
  time.sleep(0.1)


if __name__ == "__main__":
  global flag, temp
  flag, temp = 0, 0
  setup()
  color_buf = [RGBButton.e_red, RGBButton.e_green, RGBButton.e_blue, RGBButton.e_white]
  while True:
    loop()

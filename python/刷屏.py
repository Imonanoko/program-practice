# -*- coding: utf-8 -*-
"""
Created on Tue May 24 11:37:41 2022

@author: Six square
"""

import pyautogui as pg
import pyperclip
import time as t
t.sleep(5)
text='string'
for i in range(0,3):
    pyperclip.copy("text")
    pg.hotkey('ctrl', 'v')
    pg.press("Enter")
    t.sleep(1)

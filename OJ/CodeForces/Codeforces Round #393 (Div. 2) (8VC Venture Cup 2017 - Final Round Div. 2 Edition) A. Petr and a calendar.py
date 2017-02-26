# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 17:05:47
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 17:17:25

from math import ceil

days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m, d = map(int, raw_input().split())
num = int(ceil((days[m]-8+d)/7.0))
print num + 1
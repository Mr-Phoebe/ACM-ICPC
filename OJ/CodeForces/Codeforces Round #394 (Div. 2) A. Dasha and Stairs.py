# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 19:55:55
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 20:11:37

R = lambda:map(int,raw_input().split())

a,b = R()
if abs(a-b)<=1 and (a != 0 or b != 0):
    print "YES"
else:
    print "NO"
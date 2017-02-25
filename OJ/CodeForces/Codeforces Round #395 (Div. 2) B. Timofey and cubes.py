# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 20:11:52
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 20:21:18

R = lambda:map(int,raw_input().split())

n = input()
a = raw_input().split()

i = 0
while i<=(n-1)/2:
    a[i],a[-i-1] = a[-i-1],a[i]
    i+=2

print ' '.join(a)

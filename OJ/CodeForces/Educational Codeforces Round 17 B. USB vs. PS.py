# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 16:15:56
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 16:49:21

R = lambda:map(int,raw_input().split())

usb, ps, both = R()
n = int(input())
num = []

for i in range(n):
    item = raw_input().split()
    num.append((int(item[0]), item[1]))

num.sort()

t,v = 0, 0

for x,y in num:
    if y[0] == 'U':
        if usb:
            usb-=1
            t+=1
        elif both:
            both-=1
            t+=1
        else:
            continue
    else:
        if ps:
            ps-=1
            t+=1
        elif both:
            both-=1
            t+=1
        else:
            continue
    v+=x

print t,v

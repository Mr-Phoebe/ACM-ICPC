# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 17:27:02
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 17:57:49

R = lambda:map(int,raw_input().split())
C = lambda v:[(v[i]-v[i+1]+l)%l for i in range(n-1)] + [(v[n-1]-v[0]+l)%l]

n,l =R()
a = R()
b = R()
a = C(a)
b = C(b)

for i in range(n):
    if a == b:
        print 'YES'
        exit(0)
    else:
        x = a.pop()
        a = [x] + a

print 'NO'
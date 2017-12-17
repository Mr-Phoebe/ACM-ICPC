# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 21:22:14
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 21:44:53

a, b, t = map(int, raw_input().split())
n = int(input())
if n:
    arr = map(int,raw_input().split(' '))
else:
    arr = []
ma = 1e12+7
ans = 0L

for k in arr:
    if k+t <= b:
        if k and max(a, k-1)+t <= b and a-k+1 < ma:
            ma = a-k+1
            ans = min(k-1, a)
        a = max(a, k)+t

if a+t<=b:
    ans = a

print ans
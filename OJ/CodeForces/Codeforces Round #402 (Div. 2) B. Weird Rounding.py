# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 19:36:30
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 19:46:15

n, k = map(int, raw_input().split())
s = list(str(n))[::-1]
l = len(s)
ans = 0
zero = 0
for i in s:
    if i != '0':
        ans+=1
    else:
        k-=1
        zero+=1
    if k == 0:
        break

if k == 0:
    print ans
else:
    ans+=(zero-1)
    print ans

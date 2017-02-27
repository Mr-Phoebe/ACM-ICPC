# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-27 15:51:31
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-27 16:11:26

a = raw_input()
b = raw_input()
c = [i-1 for i in list(map(int, raw_input().split()))]

n = len(a)
nn = len(b)
l = 0
r = n

while l+1 < r:
    mid = l + (r-l)//2
    d = list(a)
    j = 0

    for i in range(mid):
        d[c[i]] = ''
    for i in range(n):
        if d[i] == b[j]:
            j+=1
            if j == nn:
                l = mid
                break
    if j != nn:
        r = mid

print l
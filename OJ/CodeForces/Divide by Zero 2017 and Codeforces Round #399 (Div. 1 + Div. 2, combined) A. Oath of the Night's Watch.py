# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-24 20:39:34
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-24 20:43:10

n = input()
a = map(int, raw_input().split())

a.sort()

ans = 0
l = len(a)
mi = a[0]
ma = a[l-1]

for i in range(1,l-1):
    if a[i]>mi and a[i]<ma:
        ans+=1

print ans
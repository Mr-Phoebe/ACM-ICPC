# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-27 17:00:11
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-27 17:16:23

n, m, k = map(int, raw_input().split())
m -= n

dis = 0
ans = 1

while m > 1 and dis != max(k-1, n-k):
    ans += 1
    m -= 1
    l = min(dis, k-1)
    r = min(dis, n-k)
    dis += 1
    m -= r+l

ans += m/n
print ans

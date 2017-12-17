# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 19:48:42
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 19:57:24

n, k = map(int, raw_input().strip().split())
x = map(int, raw_input().strip().split())
y = map(int, raw_input().strip().split())

z = [x[i]-y[i] for i in xrange(n)]
z.sort()
ans = sum(y)
i = 0
while i < k or (i < n and z[i] < 0):
    ans += z[i]
    i += 1
print ans



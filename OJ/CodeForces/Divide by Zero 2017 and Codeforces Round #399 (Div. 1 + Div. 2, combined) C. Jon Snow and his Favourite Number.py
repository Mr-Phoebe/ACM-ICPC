# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 11:12:05
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 12:06:04

n,k,x = map(int,raw_input().split());
a = map(int,raw_input().split());
k %= 64
for i in range(k):
    a = sorted(a)
    for j in range(n):
        if j%2 == 0:
            a[j] ^=x 
print max(a),min(a)
# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-02 10:14:55
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-02 10:45:15

n = int(input())
p = [0]+list(map(int,input().split()))
d = set()
for i in range(1,n+1):
    if p[p[i]] == i:
        d.add(min(i,p[i]))
print(len(d))
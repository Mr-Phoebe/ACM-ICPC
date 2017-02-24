# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-24 17:39:57
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-24 18:46:01

from math import log,ceil

def solve(l,r,L,R,num):
    if L > R and l > r:
        return 0
    mid = (L+R)/2
    if r<mid:
        return solve(l, r, L, mid-1, num/2)
    elif l>mid:
        return solve(l, r, mid+1, R, num/2)
    else:
        return solve(l, mid-1, L, mid-1, num/2) + solve(mid+1, r, mid+1, R, num/2) + num%2

n,l,r=map(long,raw_input().split())
if n == 0:
    print 0
else:
    p = ceil(log(n+0.5,2))
    s = pow(2, p) - 1
    print solve(l, r, 1, s, n)


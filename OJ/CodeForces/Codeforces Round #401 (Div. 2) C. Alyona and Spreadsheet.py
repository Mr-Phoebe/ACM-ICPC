# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 10:09:57
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 10:37:46

n,m = map(int, raw_input().split())
a = []

for i in range(n):
    a.append(map(int, raw_input().split()))


dp = [1 for i in range(m)]
ma = [0 for i in range(n)]

for i in range(1, n):
    for j in range(m):
        if a[i][j] >= a[i-1][j]:
            dp[j] += 1
            ma[i] = max(ma[i], dp[j])
        else:
            dp[j] = 0
k = input()
for i in range(k):
    l,r = map(int, raw_input().split())
    l-=1;r-=1;
    if l >= r-ma[r]:
        print "Yes"
    else:
        print "No"


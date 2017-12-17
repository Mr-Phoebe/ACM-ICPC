# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 15:31:28
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 15:47:32

R = lambda:map(int,raw_input().split())
def T(c):
    if c >= '0' and c <= '9':
        return 0
    if c == '#' or c == '*' or c == '&':
        return 1
    return 2

n,m = R()
dp = [[55 for i in range(3)] for i in range(n)]
s = []

for i in range(n):
    st = list(raw_input())
    s.append(st)

for i in range(n):
    for j in range(m):
        ty = T(s[i][j])
        dp[i][ty] = min(dp[i][ty], min(j,m-j))

ans = 55*3

for i in range(n):
    for j in range(n):
        if i == j:
            continue
        for k in range(n):
            if j==k or k==i:
                continue
            ans = min(ans,dp[i][0]+dp[j][1]+dp[k][2]) 

print ans
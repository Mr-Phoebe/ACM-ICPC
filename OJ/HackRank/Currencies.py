# -*- coding: utf-8 -*-
# @Author: Haonan Wu
# @Date:   2017-09-15 22:15:45
# @Last Modified by:   lenovo
# @Last Modified time: 2017-09-15 22:16:13

from math import log, inf

class Matrix:
    def __init__(self, n = 0):
        self.n = n
        self.a = [[0 for i in range(22)] for j in range(22)]
        self.la = [[-inf for i in range(22)] for j in range(22)]

    def multiply(self, b):
        n = self.n
        c = Matrix(n)

        for i in range(n):
            for j in range(n):
                maxn = 0
                maxnlog = -inf
                for k in range(n):
                    if self.la[i][k] + b.la[k][j] > maxnlog:
                        maxnlog = self.la[i][k] + b.la[k][j]
                        maxn = (self.a[i][k] * b.a[k][j])%1000000007;
                c.a[i][j] = maxn
                c.la[i][j] = maxnlog
        return c


MOD = 1000000007
n = int(input())
x, s, f, m = map(int, input().split())

ans = Matrix(n)
a = Matrix(n)

for i in range(n):
    tmp = input().split()
    for j in range(n):
        a.a[i][j] = int(tmp[j])
        a.la[i][j] = -10**50 if int(tmp[j])==0 else log(int(tmp[j]))
    ans.a[i][i] = 1
    ans.la[i][i] = 0

while m != 0:
    if m&1:
        ans = ans.multiply(a)
    a = a.multiply(a)
    m >>= 1

print((ans.a[s][f]*x)%MOD)

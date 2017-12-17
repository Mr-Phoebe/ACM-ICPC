# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-01 10:25:33
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-01 10:49:47

n = input()
u = []
v = []
for i in range(n-1):
    a, b = map(int, raw_input().split())
    u.append(a)
    v.append(b)

c = [0] + map(int, raw_input().split())

e = 0
dic = {}

for i in range(1, n+1):
    dic[i] = 0

def plus(dic, n):
    if dic.has_key(n):
        dic[n] += 1
    else:
        dic[n] = 1

for i in range(n-1):
    if c[u[i]] != c[v[i]]:
        e += 1
        dic[u[i]] += 1
        dic[v[i]] += 1

for i in range(1, n+1):
    if dic[i] == e:
        print "YES\n%d" % i
        exit(0)

print "NO"
# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-02 11:07:59
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-02 11:19:45

n = input()
a = map(int, raw_input().split())

if sum(a) != 0:
    print "YES\n1\n1 %d"%(n)
else:
    f = 0
    for i in range(n-1, -1, -1):
        if a[i]:
            f = i
            break
    if f > 0:
        print "YES\n2\n1 %d\n%d %d"%(f,f+1,n)
    else:
        print "NO"
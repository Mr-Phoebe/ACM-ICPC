# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-24 18:52:02
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-24 19:02:35

n = input()

if n <= 2:
    print 1
    for x in xrange(1,n+1):
        print 1," ",
else:    
    p = [0 for i in range(n+10)]
    for i in range(2,n+5):
        if p[i]==0:
            for j in range(i+i, n+5, i):
                p[j] = 1
    print 2
    for x in xrange(1,n+1):
        if p[x+1] == 1:
            print 2," ",
        else:
            print 1," ",
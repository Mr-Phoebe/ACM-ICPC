# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-27 16:54:40
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-27 16:56:42

a,b = raw_input().split()
print a,b
n = input()
for _ in xrange(n):
    c,d = raw_input().split()
    if c == a:
        a = d
    else:
        b = d
    print a,b
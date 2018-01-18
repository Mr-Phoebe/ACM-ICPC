# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-24 21:13:42
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-24 21:23:27


n = input()
a = map(int, raw_input().split())

b = [0 for i in range(n+10)]
num = n
for i in a:
    b[i] = 1
    while b[num]:
        print num,
        num -= 1
    print ""

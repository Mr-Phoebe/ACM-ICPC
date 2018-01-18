# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 09:40:02
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 09:51:39

n = input()
a = list(sorted(raw_input()))
b = list(sorted(raw_input()))

j = 0
for i in b:
    if i >= a[j]:
        j+=1
    if j >= n:
        break
print n-j

j = 0
for i in b:
    if i > a[j]:
        j+=1
    if j >= n:
        break
print j 



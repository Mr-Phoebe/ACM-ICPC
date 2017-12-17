# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-26 19:15:45
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-26 19:29:18

n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
s=0
for i in range(1,6):
    x=a.count(i)
    y=b.count(i)
    if not (x+y)%2:s+=abs(x-y)//2
    else:exit(print(-1))
print(s//2)


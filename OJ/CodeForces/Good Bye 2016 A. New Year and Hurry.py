# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-02 19:26:42
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-02 19:33:31

n,k=map(int,raw_input().split())
t=240-k
i=0
while i<n and 5*(i+1)<=t:
    
  i+=1
  t-=5*i
print i
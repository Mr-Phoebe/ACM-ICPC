# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 19:18:19
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 19:30:46

R = lambda:map(int,raw_input().split())
k, a, b = R()

print -1 if b<k and a%k!=0 or a<k and b%k!=0 else a/k+b/k
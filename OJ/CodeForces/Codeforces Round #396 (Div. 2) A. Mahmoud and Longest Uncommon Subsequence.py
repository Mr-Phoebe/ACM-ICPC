# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 14:42:03
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 14:42:51

a = list(raw_input())
b = list(raw_input())

if a == b:
    print -1
else:
    print max(len(a), len(b))

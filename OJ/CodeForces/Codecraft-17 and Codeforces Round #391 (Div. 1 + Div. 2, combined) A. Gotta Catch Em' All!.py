# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-27 20:28:48
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-27 20:31:48

s = raw_input()
t = min(s.count(c) for c in 'Bblsr')
t = min(t,min(s.count(c)/2 for c in 'ua'))
print t
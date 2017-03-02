# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-02 09:43:19
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-02 09:53:59

n, m = map(int, raw_input().split())
a = [raw_input() for i in xrange(n)]
b = [raw_input() for i in xrange(m)]
if len(set(a+b)) % 2: n += 1
print "YES" if n>m else "NO"
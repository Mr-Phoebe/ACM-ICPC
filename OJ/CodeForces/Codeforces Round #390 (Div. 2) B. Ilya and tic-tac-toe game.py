# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-02 14:35:01
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-02 15:43:46
def check(q, w, e):
    return sorted([q, w, e]) == ['.', 'x', 'x']

t = ['qq' + raw_input() + 'qq' for _ in xrange(4)] + ['qqqqqqqq', 'qqqqqqqq']

dir = [ (1, 0), (0, 1), (1, 1), (1, -1) ]

for y in xrange(4):
    for x in xrange(2, 6):
        for d in dir:
            if check(t[y][x], t[y+d[0]][x+d[1]], t[y+2*d[0]][x+2*d[1]]):                
                print "YES"
                exit(0)
print "NO"

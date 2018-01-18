# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-25 16:59:21
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-25 17:06:13

s = map(ord,raw_input())
cur = [96]
cnt = 0

for c in s:
    if c > cur[cnt]:
        if c == cur[cnt]+1:
            cnt+=1
            cur.append(c)
        else:
            print "NO"
            exit(0)
print "YES"

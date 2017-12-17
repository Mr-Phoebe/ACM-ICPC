# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-28 16:36:39
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-28 16:52:29

from collections import Counter

MAXN = 100001
n = input()
b = Counter(map(int, raw_input().split()))

ma = 1
for i in range(2, MAXN):
    ans = 0
    for j in range(i, MAXN, i):
        ans += b[j]
    ma = max(ma, ans)

print ma





# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-27 16:23:41
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-27 16:53:18

from itertools import permutations

def plus(dic, s, n):
    if dic.has_key(s):
        dic[s] += n
    else:
        dic[s] = n

def check(ori, st):
    n = len(ori)
    j = 0
    for i in range(n):
        if ori[i] == '!' or ori[i] == st[j]:
            j = (j+1)%4
        else:
            return False
    return True

def get(ori, st):
    n = len(ori)
    j = 0
    dic = {}
    for i in range(n):
        if ori[i] == '!':
            plus(dic, st[j], 1)
        j = (j+1)%4

    return dic 

a = list(raw_input())

for st in permutations('RYBG', 4):
    if check(a, st):
        dic = get(a, st)

for i in ['R', 'Y', 'B', 'G']:
    plus(dic, i, 0)


print dic['R'], dic['B'], dic['Y'], dic['G']


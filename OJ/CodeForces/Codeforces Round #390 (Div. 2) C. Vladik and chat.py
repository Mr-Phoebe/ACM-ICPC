# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-02 15:37:06
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-02 16:19:37

from re import * 
t = input()
for _ in range(t):
    n = input()
    names = set(raw_input().split())

    m = input()
    messages = []
    possibles = []
    for i in range(m):
        s, msg = raw_input().split(':')
        messages.append(msg)

        tokens = split(r"[^A-Za-z0-9]", msg)
        mentioned = names & set(tokens)

        if s == '?':
            possibles.append( names - mentioned )
        else:
            possibles.append({s})

        if i and len(possibles[i-1]) == 1:
            possibles[-1] -= possibles[i-1]

    if any( [len(p) == 0 for p in possibles] ):
        print "Impossible"
    else:
        for i in reversed(range(m)):
            possibles[i] = possibles[i].pop()
            if i:
                possibles[i-1].discard(possibles[i])

        for i in range(m):
            print ":".join( (possibles[i], messages[i]))
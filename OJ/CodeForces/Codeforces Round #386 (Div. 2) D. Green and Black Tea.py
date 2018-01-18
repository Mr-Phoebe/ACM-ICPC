import math
n, k, a, b = map(int,raw_input().split())
if float(max(a,b))/(float(min(a,b))+1) > k:
    print "NO"
else:
    if a > b:
        w="GB"
    else:
        a, b = b, a
        w = "BG"
    ans = ""
    c = int(math.floor(float(a)/float(b+1)))
    for i in xrange(b+1):
        d = 1 if i<a%(b+1) else 0
        ans += w[0]*(c+d)
        if i != b:
            ans += w[1]
    print ans
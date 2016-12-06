a,b,c,d = map(int,raw_input().split())

print 256*min(a,c,d)+min(b,a-min(a,c,d))*32
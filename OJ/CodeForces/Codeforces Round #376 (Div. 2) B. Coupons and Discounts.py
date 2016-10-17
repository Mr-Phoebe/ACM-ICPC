n = int(raw_input())
a = [int(x) for x in raw_input().split()]
pre = 0
for i in a:
    if(i==0 and pre!=0):
        print 'NO'
        exit()
    if(i%2!=0):
        pre = (pre+1)%2
    else:
        pre = pre%2
if(pre%2 != 0):
    print 'NO'
else:
    print 'YES'


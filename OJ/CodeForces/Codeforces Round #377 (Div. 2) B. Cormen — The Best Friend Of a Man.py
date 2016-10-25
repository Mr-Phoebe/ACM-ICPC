R = lambda: map(int, raw_input().split())
n,k=R()
a=R()
s=0
b=a[0]
for i in range(1,n):
    if b+a[i]<k:
        s+=k-b-a[i]
        a[i]=k-b
    b=a[i]
print(s)
for i in xrange(n):
    print a[i],
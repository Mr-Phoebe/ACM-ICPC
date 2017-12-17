n,b,d = map(int,raw_input().split())
z = map(int,raw_input().split())
sum1,ans = 0,0
for i in z:
    if i <= b:
        sum1 += i
    if sum1 > d:
        sum1=0
        ans+=1
print ans
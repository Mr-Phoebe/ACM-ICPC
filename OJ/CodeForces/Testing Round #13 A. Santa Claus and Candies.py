n=input()
arr=[]
i=1

while i <= n:
    arr.append(i)
    n-=i
    i+=1

arr[-1]+=n
print len(arr)
for i in arr:
    print i,
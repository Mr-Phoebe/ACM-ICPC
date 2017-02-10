n = input()
a = map(int,raw_input().split()) 
a.sort()
for i in range(1,n-1):
    if(a[i-1]+a[i]>a[i+1]):
        print("YES")
        exit()
print("NO") 
n=input()
a=map(int,raw_input().split())+[0]
for i in range(n):
  print a[i]+a[i+1],
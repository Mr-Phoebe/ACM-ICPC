n,m,k,x,y=map(int,raw_input().split())
s=(n+max(0,n-2))*m
b=k/s
k%=s
v=[[b]*m for i in range(n)]
for i in range(1,n-1):
  for j in range(m):
    v[i][j]+=b

i,j,d=0,0,1
while k:
  v[i][j]+=1
  k-=1
  j+=1
  if j==m:
    j=0
    if i+d>=n:
      d=-1
    i+=d

print max(map(max,v)),min(map(min,v)),v[x-1][y-1]
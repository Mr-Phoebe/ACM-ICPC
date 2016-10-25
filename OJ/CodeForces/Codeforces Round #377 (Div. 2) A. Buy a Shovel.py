k,r=map(int,raw_input().split())
for x in range(1,123):
  if k*x%10 in (0,r):
    print x
    break
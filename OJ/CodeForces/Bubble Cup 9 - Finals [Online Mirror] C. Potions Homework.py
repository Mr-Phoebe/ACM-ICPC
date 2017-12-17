N=range(input())
a=sorted(input() for _ in N)
print sum(a[i]*a[-1-i] for i in N)%10007
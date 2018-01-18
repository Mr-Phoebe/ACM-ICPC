n, m = map(int, raw_input().split())
ans = 100000000;
for i in range(m):
	a,b = map(int, raw_input().split())
	ans = min(ans, b-a+1)
print ans
print(' '.join(str(i%ans) for i in range(n)))
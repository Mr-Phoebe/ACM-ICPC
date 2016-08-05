n, k = map(int,raw_input().strip().split())
C = map(int,raw_input().strip().split())
K = map(int,raw_input().strip().split())

S = 0
for i in C:
    S += i
D = 0

R = 0
for i in xrange(k):
    K[i] -= 1
for i in K:
    S -= C[i]
    R += C[i] * S
    C[i] = 0

for i in xrange(n):
    j = (i + 1) % n
    R += C[i]*C[j]

print R
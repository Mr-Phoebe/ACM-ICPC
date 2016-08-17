a, b = map(int, raw_input().split())
n = int(raw_input())
c = []
for _ in range(n):
    x, y, v = map(int, raw_input().split())
    c.append(((a-x)**2 + (b-y)**2)**0.5/v)
print min(c)
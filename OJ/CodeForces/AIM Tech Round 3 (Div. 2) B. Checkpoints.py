n, a = map(int, raw_input().split())
x = sorted(map(int, raw_input().split()) + [a] * 3)
n += 3
res = 2 * abs(x[n - 1] - a) + abs(x[1] - a)
res = min(res, 2 * abs(x[1] - a) + abs(x[n - 1] - a))
res = min(res, 2 * abs(x[n - 2] - a) + abs(x[0] - a))
res = min(res, 2 * abs(x[0] - a) + abs(x[n - 2] - a))
print res
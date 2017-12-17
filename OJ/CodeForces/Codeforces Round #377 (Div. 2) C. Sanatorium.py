a = sorted(map(int, raw_input().split()))
print max(a[2]-a[0]-1, 0) + max(a[2]-a[1]-1, 0)
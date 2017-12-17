n = int(input())
m = 0; k = 0
while n:
	l = map(int, raw_input().split())
	m += l[0] > l[1]
	k += l[0] < l[1]
	n -= 1
if m == k:
	print "Friendship is magic!^^"
else:
	if m < k:
		print "Chris"
	else:
		print "Mishka"
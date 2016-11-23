n=input()
s=raw_input()
c=s.count('A')

if c>n/2.0:
	print 'Anton'
elif c<n/2.0:
	print 'Danik'
else:
	print "Friendship"
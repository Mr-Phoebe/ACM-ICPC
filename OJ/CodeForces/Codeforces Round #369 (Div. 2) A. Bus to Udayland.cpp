
 n = input()

s = ''
for i in xrange(n):
    s+=raw_input()
    s+='\n'
if 'OO' in s:
    print 'YES'
    print s.replace('OO','++',1).strip()
else:
    print 'NO'
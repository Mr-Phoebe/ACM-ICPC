import string

s = raw_input()

if len(s)< 26:
	print -1
else:
	works = False
	for i in xrange(len(s)-25):
		qmarks = s[i:i+26].count("?")
		arr = []
		missing = []
		for char in string.uppercase:
			arr.append(s[i:i+26].count(char))
			if s[i:i+26].count(char) == 0:
				missing.append(char)
		#print arr, missing, qmarks
		if arr.count(1) != 26 - qmarks:
			continue
		else:
			for mchar in missing:
				s = s[:i] + s[i:i+26].replace("?",mchar,1) + s[i+26:]
			works = True
			s = s.replace("?","A")
			print s
			break
	if not works:
		print -1
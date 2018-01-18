name = 'a' + raw_input()
sum = 0
for i in range(1,len(name)):
    r = abs(ord(name[i]) - ord(name[i-1]))
    sum = sum + min(r,26-r)
print sum
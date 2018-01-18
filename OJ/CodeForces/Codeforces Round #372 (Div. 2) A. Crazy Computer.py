n,c=map(int,raw_input().split())
a=map(int,raw_input().split())
r=0
p=0
for aa in a:
    if aa-p>c:
        r=0
    r+=1
    p=aa   
print r  
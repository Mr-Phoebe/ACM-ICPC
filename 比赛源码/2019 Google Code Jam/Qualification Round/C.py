from math import *

def main():
    T = int(input())
            
    for _t in range(1, T + 1):
        dummy, n = map(int, input().split())
        a = [int(e) for e in input().split()]
        b = [0] * (n + 1)
        p = -1
        for i in range(n - 1):
            if a[i] != a[i + 1]:
                p = i
        b[p + 1] = gcd(a[p], a[p + 1])
        for i in range(p, -1, -1):
            b[i] = a[i] // b[i + 1]
        for i in range(p + 2, n + 1):
            b[i] = a[i - 1] // b[i - 1]
        c = b.copy()
        c.sort() 
        m = dict()
        cnt = 0
        lst = -1 
        for e in c:
            if e != lst:
                lst = e
                m[e] = cnt
                cnt += 1
        ans = ''.join(chr(m[e] + 65) for e in b)
        print("Case #{}: {}".format(_t, ans))


if __name__ == '__main__':
    main()
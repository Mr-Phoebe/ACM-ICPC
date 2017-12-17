#include <bits/stdc++.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-8
#define MAX_N 1010
#define INF 1 << 30
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1005
#define N 105
#define INF 1<<30
#define eps 1.0e-10

#define For(i,m,n) for(i=(m);i<n;i++)
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)

int isprime(int x)
{
    int i;
    for(i = 2; i*i <= x; i++) if(x%i == 0) return 0;
    return 1;
}

int main()
{
    int i, flag, t, x;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &x);
        flag = 0;
        for(i=2; i*i <= x; i++)
        {
            if(x%i == 0 && isprime(i))
            {
                if(isprime(x/i)) flag=1;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}

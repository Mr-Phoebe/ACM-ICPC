#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 500



int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 8) puts("0");
    else if(n == 9) puts("8");
    else
    {
        putchar('7');
        putchar('2');
        rep(i, 10, n) putchar('0');
        puts("");
    }
    return 0;
}

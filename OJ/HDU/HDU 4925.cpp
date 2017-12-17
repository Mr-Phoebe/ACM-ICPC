#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#define pi acos(-1.0)
#define eps 1e-8
#define ll long long
#define L 1000050
#define N 1050
#define Mod 1000000007
#define M 99999999999
#define clr(a) memset(a,0,sizeof(a))
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}

int main()
{
    int i,j,k,n;
    int cas=1;
    int a,b;
    //ios::sync_with_stdio(false);
    read(n);
    while(n--)
    {
        read(a),read(b);
        if(a==1&&b==1)
            printf("1\n");
        else
        {
            if(a>b)
                swap(a,b);
            if(a==1)
                printf("%d\n",2*(b-1));
            else
                printf("%d\n",(a-1)*(b-1)*8);
        }
        //printf("Case #%d: %d\n",cas++,res);
    }
    return 0;
}

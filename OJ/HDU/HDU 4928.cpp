#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<map>
#define pi acos(-1.0)
#define eps 1e-8
#define ll long long
#define L 1000050
#define N 100050
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

long long a[N];
int main()
{
    int i,j,k,n;
    int cas=1;
    int t,sig1,sig2,l,r;
    read(T);
    while(T--)
    {
        read(n);
        for(i=0;i<n;i++)
            read(a[i]);
        l=0;
        r=n-1;
        for(i=0;i<n-1;i++)
        {
            while(l<r&&!a[l])   i++;
            if(l<1)
                l=0;
            else
                l=l-1;
            while(r>l&&!a[r])   r--;
            if(r+1>n-i-1)
                r=n-i-1;
            else
                r=r+1;
            if(l>=r)
                break;
            sig1=sig2=1;
            for(j=l;j<r;j++)
            {
                if(a[j+1]<a[j])
                    sig1=0;
                else if(a[j+1]>a[j])
                    sig2=0;
            }
            if(!sig1&&!sig2)
            {
                if(i==0)
                    printf("ugly series\n");
                else
                    printf("%d\n",i-1);
                break;
            }
            for(j=l;j<r;j++)
                a[j]=a[j+1]-a[j];
            r--;
        }
        if(sig1||sig2)
            printf("nice series\n");
    }
    //printf("Case #%d: %d\n",cas++,res);
    return 0;
}

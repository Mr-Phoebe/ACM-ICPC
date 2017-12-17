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

double s[N][2];
int main()
{
    int i,j,k,n;
    int cas=1;
    int a,b;
    int t;
    double x;
    int num=0;
    for(read(t); t--;)
    {
        read(n);

        s[0][0]=1;
        s[0][1]=1;
        num=0;
        for(i=1; i<=n; i++)
        {
            read(x);
            s[num][0]=x;
            s[num][1]=1;

            num++;
            while(num>=2)
            {
                if((s[num-1][0]/s[num-1][1])>(s[num-2][0]/s[num-2][1]))break;
                s[num-2][0]+=s[num-1][0];
                s[num-2][1]+=s[num-1][1];
                num--;
            }
        }
        double res=0;
        for(i=0; i<num; i++)
        {
            double tmp=s[i][0]/s[i][1];
            res+=tmp*tmp*(s[i][1]-s[i][0])+(1-tmp)*(1-tmp)*(s[i][0]);
        }
        printf("%.6lf\n",res);
        //printf("Case #%d: %d\n",cas++,res);
    }
    return 0;
}

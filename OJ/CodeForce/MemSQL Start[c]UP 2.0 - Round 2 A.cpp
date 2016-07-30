#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

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
//-----------------------------------

const int MAXN=100010;

char s1[MAXN],s2[MAXN];
int num[MAXN], num2[MAXN];

int main()
{
    int n, m;
    gets(s1);
    gets(s2);
    int len=strlen(s1), len2=strlen(s2);
    int maxx=max(len,len2);
    for(int i=len-1; i>=0; i--)
        num[len-i-1]=s1[i]-'0';
    for(int i=len2-1; i>=0; i--)
        num2[len2-i-1]=s2[i]-'0';
    for(int i=maxx+5; i>=0; i--)
    {
        int minn=min(num[i],num[i-1]);
        if(minn)
        {
            num[i]-=minn, num[i-1]-=minn, num[i+1]+=minn;
            i+=3;
        }
    }
    for(int i=maxx+5; i>=0; i--)
    {
        int minn=min(num2[i],num2[i-1]);
        if(minn)
        {
            num2[i]-=minn, num2[i-1]-=minn, num2[i+1]+=minn;
            i+=3;
        }
    }
//    for(int i=maxx+5;i>=0;i--)
//        cout<<num[i];
//    cout<<endl;
//    for(int i=maxx+5;i>=0;i--)
//        cout<<num2[i];
//    cout<<endl;
    for(int i=maxx+5; i>=0; i--)
    {
        if(num[i]>num2[i])
        {
            puts(">");
            return 0;
        }
        else if(num[i]<num2[i])
        {
            puts("<");
            return 0;
        }
    }
    puts("=");
    return 0;
}

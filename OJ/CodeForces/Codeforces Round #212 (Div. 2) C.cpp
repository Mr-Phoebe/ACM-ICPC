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
#define lowbit(x) (x&(-x))

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
    T x = 0, tmp = 1; char c = getchar();
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

//我们枚举pair(A[i], A[j])，且i < j。
//此时对于逆序数的变化值为 (A[i+1 ... j-1]中小于j的数的个数) + (A[i+1 ... j-1]中大于i的个数)

const int MAXN=5555;
int a[MAXN];  
int po[MAXN];  
int dp[MAXN][MAXN];  

int main()  
{  
    int n,i,j;  
    read(n);  
    for(i=0; i<n; i++)  
    {  
        read(a[i]);  
        po[a[i]]=i;  
    }  
    for(i=0; i<n; i++)  
        for(j=n-1;j>=0;j--)  
        {  
            if(a[j]<i)
				dp[i][j]++;  
            dp[i][j]+=dp[i][j+1];  
        }  
    int sum=0;  
    for(i=0;i<n;i++)  
        sum+=dp[i][po[i]];  
    int minn=sum,num=0;  
    for(i=0; i<n; i++)  
    {  
        for(j=0; j<i; j++)  
        {  
            if(a[i]>a[j])
				continue;    
            int aa=dp[a[i]][j]-dp[a[i]][i];  
            int bb=dp[a[j]][j]-dp[a[j]][i];  
            int change=sum+2*aa-(2*bb+1);  
            if(change<minn)  
                minn=change,num=1;  
            else if(change==minn)  
                num++;  
        }  
    }  
    write(minn);putchar(' ');write(num);putchar('\n');  
    return 0;  
}  
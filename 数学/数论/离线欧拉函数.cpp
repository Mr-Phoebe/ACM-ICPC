//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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


const int MAXN=1000010;  
int phi[MAXN];  
int num[MAXN];  
  
void init()  
{   
    phi[1]=1;  
    for(int i=2;i<MAXN;i++)  
      if(!phi[i])  
        for(int j=i;j<MAXN;j+=i)  
        {  
            if(!phi[j])
				phi[j]=j;  
            phi[j]=phi[j]/i*(i-1);  
        }  
}  
int main()  
{  
	int n,T,cas=1;
    init();  
    read(T);    
    while(T--)  
    {  
        read(n);  
    	for(int i=0;i<n;i++)
			read(num[i]);  
        sort(num,num+n);  
        ll sum=0;  
        for(int i=0,j=2;i<n;)  
        {  
            if(phi[j]>=num[i])  
            {  
                sum+=j;  
                i++;  
            }  
            else j++;  
        }  
        printf("Case %d: %lld Xukha\n",cas++,sum);  
    }  
    return 0;  
}  
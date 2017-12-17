#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-10
#define INF 0x7fffffff
#define maxn 10005
#define PI acos(-1.0)
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

int a[505][1005];
int num[505][2];
int main()
{
    int n,cas=0;
    int ans[505];
    while(read(n)&&n)
    {
        memset(ans,-1,sizeof(ans));
        memset(num,0,sizeof(num));
        printf("Case #%d:",++cas);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                read(a[i][j*2+1]),read(a[i][j*2+2]);
                num[a[i][j*2+1]][0]++;
                num[a[i][j*2+2]][1]++;
            }
        if(n==2)
        {
            if(num[0][0]>num[1][0])
                printf(" 0 1\n");
            else
				printf(" 1 0\n");
    		continue;
        }
        int ma=0,pos=0;
        for(int i=0; i<n; i++)			//出现个数最多的是 0  
            if(num[i][0]+num[i][1]>ma)
            {
                ma=num[i][0]+num[i][1];
                pos=i;
            }
        ans[0]=pos;    
        for(int j=0; j<n; j++)			//十位数全是 0 的数字，而且个位数每一个都不一样的一定是 1 
        {
        	if(a[0][2*j+1]!=ans[0])
        		continue;
        	int i=1;
        	for(; i<n; i++)
	        	if(a[i][2*j+2]==a[i-1][2*j+2] || a[i][2*j+1]!=a[i-1][2*j+1])
        			break;
   			if(i==n)
			{
				ans[1]=j;
				break;
			}
        }
        for(int i=0;i<n;i++)
            if(num[i][0]==1)				//十位数只出现一次的必定是 n-2 的位置 
            {
                ans[n-2]=i;
                break;
            }
        for(int i=0;i<n;i++)			//十位数对应为最大的数必定是 n-1 的位置 
            if(a[i][i*2+1]==ans[n-2])
            {
                ans[n-1]=i;
                break;
            }
        for(int i=2;i<n-2;i++)			//知道位置之后开始递推 
            ans[n-i-1]=a[ans[n-1]][2*ans[n-i]+1];
        for(int i=0;i<n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
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

int p,n,mapp[111][111],minn=INF;
bool vis[20];

bool judge()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int k=0;
			for(;k<p;k++)
				if(vis[k] && mapp[i][k]!=mapp[j][k])
					break;
			if(k==p)
				return false;
		}
	}
	return true;
}

void find(int po)  
{  
    int num=0;  
    for(int j=0;j<p;j++)  
    	if(vis[j])  
        	num++;  
    if(judge()==1 && num!=0 && minn>num)    
        	minn=num;    
    if(po<p)  
    {  
        vis[po]=1;  
        find(po+1);  
        vis[po]=0;  
        find(po+1);  
    }  
}  

int main()
{
	int T;
	read(T);
	while(T--)
	{
		minn=INF;
		read(p),read(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<p;j++)
				read(mapp[i][j]);
		find(0);
		write(minn);putchar('\n');
	}
	return 0;	
} 
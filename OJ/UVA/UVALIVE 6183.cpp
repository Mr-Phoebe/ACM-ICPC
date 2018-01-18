//      whn6325689
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
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

int n,m;

int num[15][4];
vector<int> v[3];
int R,C,S;

bool judge()
{
	for(int i=0;i<n;i++)
		if(num[i][0]!=R*num[i][1]+C*num[i][2]+S*num[i][3])
			return false;
	return true;
}

int check(int r,int c,int s)
{
    int cnt=v[0][0]*r+v[1][0]*c+v[2][0]*s;
    for(int i=1;i<v[0].size();i++)
        if(cnt!=v[0][i]*r+v[1][i]*c+v[2][i]*s)
            return -1;
    return cnt;
}

int main()
{
	char a[111];
	while(read(n)&&read(m)&&(n+m))
	{
		int r=0,c=0,s=0,len;
        for(int i=0;i<3;i++)
            v[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s",a);
			len=0;
		 	while(a[len]=='.')
		 		len++;
			num[i][0]=len,num[i][1]=r,num[i][2]=c,num[i][3]=s;
			for(;a[len];len++)
			{
				if(a[len]=='(')		r++;
				else if(a[len]==')')	r--;
				else if(a[len]=='{')	c++;
				else if(a[len]=='}')	c--;
				else if(a[len]=='[')	s++;
				else if(a[len]==']')	s--;
			}
		}
		for(R=1;R<=20;R++)
			for(C=1;C<=20;C++)
				for(S=1;S<=20;S++)
					if(judge())
					{
					    v[0].pb(R);v[1].pb(C);v[2].pb(S);
					}
		r=0,c=0,s=0;
		for(int i=0;i<m;i++)
		{
			scanf("%s",a);
			if(i)
				putchar(' ');
			write(check(r,c,s));
 			for(len=0;a[len]!='\0';len++)
			{
				if(a[len]=='(')		r++;
				else if(a[len]==')')	r--;
				else if(a[len]=='{')	c++;
				else if(a[len]=='}')	c--;
				else if(a[len]=='[')	s++;
				else if(a[len]==']')	s--;
			}
		}
		putchar('\n');
	}
	return 0;
}

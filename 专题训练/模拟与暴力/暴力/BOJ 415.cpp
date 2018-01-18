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

//-------------------------------------------------------------------

const int MAXN=110;
const double PI=acos(-1.0);
const double sqr3=sqrt(3.0);
int mapp[MAXN][MAXN];
double ans=0.0;

void check(int x,int y)
{
	bool a=false,b=false,c=false,d=false;
	int num=0;
	if(mapp[x][y])
		a=!a,num++;
	if(mapp[x][y+1])
		b=!b,num++;
	if(mapp[x+1][y+1])
		d=!d,num++;
	if(mapp[x+1][y])
		c=!c,num++;
	if(num>=3)
		ans+=1;
	else if(num==1)
		ans+=PI/4;
	else if(num==2)
	{
		if(a&&d&&!b&&!c||!a&&!d&&b&&c)
			ans+=1;
		else if(!a&&d&&b&&!c||a&&!d&&b&&!c||!a&&d&&!b&&c||a&&!d&&!b&&c)
			ans+=PI/6+sqr3/4;
	}	
}

int main()
{
//	freopen("data.txt","r",stdin);
	int T,n;
	read(T);
	while(T--)
	{
		ans=0.0;
		memset(mapp,0,sizeof(mapp));
		read(n);
		for(int i=0;i<n;i++)
		{
			int x,y;
			read(x);read(y);
			mapp[x][y]++;
		}
		for(int i=0;i<=100;i++)
				for(int j=0;j<=100;j++)
					check(i,j);
		printf("%.5f\n",ans);
	}
} 
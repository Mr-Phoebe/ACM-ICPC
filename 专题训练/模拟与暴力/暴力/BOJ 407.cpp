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

char mapp[1010][1010];
int n,m,ans=0;
int ok=true;

void check(int x,int y)
{
	bool a=false,b=false,c=false,d=false;
	int num=0;
	if(mapp[x][y]=='#')
		a=!a,num++;
	if(mapp[x][y+1]=='#')
		b=!b,num++;
	if(mapp[x+1][y+1]=='#')
		d=!d,num++;
	if(mapp[x+1][y]=='#')
		c=!c,num++;
	if(num==3)
		ok=false;
	else if(num==1&&a)
		ans++;
	else if(num==2&&a&&d)
		ans++;
		
}

int main()
{
//	freopen("data.txt","r",stdin);
	while(read(n) && read(m))
    {
        ans=0;ok=true;
        for(int i=0;i<n;i++)
            gets(mapp[i]);
        for(int i=0;i<n&&ok;i++)
        	for(int j=0;j<m&&ok;j++)
        		check(i,j);
  		if(!ok)
            puts("So Sad");
        else
            printf("There are %d ships.\n",ans);
    }
} 
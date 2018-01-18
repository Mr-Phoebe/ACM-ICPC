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

const int MAXN=100;

int fa[MAXN],n,m;

int find_fa(int x)
{
	if(fa[x]==x)
		return x;
	else
		return fa[x]=find_fa(fa[x]);
}

void Merge(int x,int y)
{
    int xx=find_fa(x);
    int yy=find_fa(y);
    fa[xx]=fa[yy];
}

int main()
{

	scanf("%d %d",&n,&m);
	long long ans=((long long)1<<n);
	for(int i=0;i<MAXN;i++)
		fa[i]=i;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		Merge(x-1,y-1);
	}
	for(int i=0;i<n;i++)
	    if(fa[i]==i)
		    ans>>=1;
	printf("%I64d\n",ans);
	return 0;
}

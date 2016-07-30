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

int main()
{
	int n,v;
	int ans=0;
	int a[5000];
	memset(a,0,sizeof(a));
	scanf("%d %d",&n,&v);
	for(int i=0;i<n;i++)
	{
	    int d,f;
		scanf("%d %d",&d,&f);
		a[d]+=f;
	}
	int temp=0;
	for(int i=0;i<=3001;i++)
	{
		int c=v;
		if(temp<=c)
		{
			c-=temp;
			ans+=temp;
		}
		else
		{
			ans+=c;
			c=0;
		}
		if(c>=a[i])
		{
			ans+=a[i];
			temp=0;
		}
		else
		{
			temp=a[i]-c;
			ans+=c;
		}
	}
	printf("%d\n",ans);
	return 0;
}

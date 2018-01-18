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
const int maxn=100010;

int n,d,rec[maxn],tot=0;
int a[maxn],b[maxn],po[maxn];
ll x;

ll getNextX()
{
    x=(x*37+10007)%1000000007;
    return x;
}
void initAB()
{
	int i;
    for(i = 0; i < n; i = i + 1)
        a[i] = i + 1;
    for(i = 0; i < n; i = i + 1)
        swap(a[i], a[getNextX() % (i + 1)]);
    for(i = 0; i < n; i = i + 1)
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    for(i = 0; i < n; i = i + 1)
        swap(b[i], b[getNextX() % (i + 1)]);
}

void init()
{
	for(int i=0;i<n;i++)
		if(b[i])
			po[tot++]=i;//记录b中为1的位置
	for(int i=0;i<n;i++)
		rec[a[i]]=i;    //记录a中1~n的位置 
}

int main()
{
	scanf("%d %d %d",&n,&d,&x);
	initAB();
	init();
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=n;j>=n-30;j--)
			if(rec[j]<=i && b[i-rec[j]])
			{
				flag=false;printf("%d\n",j);break;
			}		
		if(flag)
		{
			int ans=0;	
			for(int j=0;j<tot && po[j]<=i;j++)
				ans=max(ans,a[i-po[j]]);
			printf("%d\n",ans);	
		}	
	}
	return 0;
} 

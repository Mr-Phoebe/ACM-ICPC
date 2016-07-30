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

#define X first
#define Y second
// #define X real()
// #define Y imag()
// #define cin fin
// #define cout fout

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int maxn = 3 * 1e5;

int a[111][111];
int n,m,b=0,ma=0;

bool judge(int t)
{
//	cout<<t<<" : "<<endl; 
	for(int k=t;k<=n/2;k*=2)
		for(int i=1;i<=k;i++)
		{
//			cout<<"\t"<<i<<" : "<<2*k-i+1<<endl;
			for(int j=1;j<=m;j++)	
				if(a[i][j]!=a[2*k-i+1][j])
					return false;
		}	
	return true;
}


int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int temp=n;
	if(temp&1)
	{
		printf("%d\n",n);
		return 0;
	}
	while(1)
	{
		temp>>=1;
		if(temp&1)
		{
			b=temp;
			break;
		}	
	}
	for(int i=b;i<=n;i*=2)
		if(judge(i))
		{
			printf("%d\n",i);
			return 0;
		}
	return 0;
}
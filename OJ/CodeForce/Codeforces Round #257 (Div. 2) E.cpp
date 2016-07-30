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
//------------------------------------------------------------------------

const int MAXN=1e5+10;

bool vis[MAXN];
vector< pair <int,int> > a;
vector<int> temp[MAXN];
int pri[MAXN];

void isprime(int n)
{
	for(int i=2;i<=n;i++)
		if(!pri[i])
			for(int j=2*i;j<=n;j+=i)
				pri[j]=1;
}

int main()
{
	int n;
	read(n);
	isprime(n);
	for(int i=n/2;i>1;i--)
	{
		if(!pri[i])
			for(int j=i;j<=n;j+=i)
			{
				if(!vis[j])
				{
					temp[i].push_back(j);
					vis[j]=1;
				}
			}
		int sz=temp[i].size();
		if(sz%2&&sz>1)
		{
			swap(temp[i][1],temp[i][sz-1]);
			vis[temp[i][sz-1]]=0;
		}	
	}
	for(int i=2;i<=n/2;i++)
		if(!pri[i])
			for(int j=0;j+1<temp[i].size();j+=2)
				a.push_back(make_pair(temp[i][j],temp[i][j+1]));
	printf("%d\n",a.size());
	for(int i=0;i<a.size();i++)
	{
		printf("%d %d\n",a[i].first,a[i].second);
	}
	return 0;
}
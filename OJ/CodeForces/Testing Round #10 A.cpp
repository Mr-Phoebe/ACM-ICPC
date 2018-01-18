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

const int MAXN=100010;

int num[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a;
		scanf("%d",&a);
		num[a]++;
	} 
	for(int i=1;i<=n;i++)
		if(!num[i])
		{
			cout<<i<<endl;
			return 0;
		}
	return 0;
}
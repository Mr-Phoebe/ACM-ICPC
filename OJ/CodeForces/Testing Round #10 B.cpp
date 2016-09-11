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
	int n;
	long long sum=0;
	long long ans=0;
	long long a[50010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}	
	long long ave=sum/n;
	for(int i=n-1;i>=1;i--)
	{
		long long temp=a[i]-ave;
		a[i-1]+=temp;
		a[i]-=temp;
		ans+=fabs(temp);
	}
	cout<<ans<<endl;
	return 0;
}
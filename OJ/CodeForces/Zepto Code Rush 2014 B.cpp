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
#include <cmath>

using namespace std;

char w[2010][2010];
int num[2010][2010];
int ans[2010];
int n,m,kk;

int main()
{
	scanf("%d %d %d\n",&n,&m,&kk);
	memset(w,0,sizeof(w));
	for(int i=0;i<n;i++)
		gets(w[i]);
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<w[i][j];
		cout<<endl;
	}*/
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(w[i][j]=='U'&&!(i&1))
				num[i/2][j]++;
			if(w[i][j]=='L'&&j-i>=0)
				num[i][j-i]++;
			if(w[i][j]=='R'&&j+i<m)
				num[i][j+i]++;
		}
	//	cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans[j]+=num[i][j];//cout<<num[i][j];
		}
		//cout<<endl;	
	}	
	for(int i=0;i<m;i++)
		printf("%d ",ans[i]);
	return 0;
}
 
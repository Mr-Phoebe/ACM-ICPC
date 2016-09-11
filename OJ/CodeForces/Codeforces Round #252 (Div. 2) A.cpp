#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 

using namespace std;

vector<int>a;

int main()
{
	int n,v;
	scanf("%d %d",&n,&v);
	for(int i=0;i<n;i++)
	{
		int m;
		bool first=true;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp<v&&first)
			{
				a.push_back(i+1);
				first=!first;	
			}
		}
	}
	printf("%d\n",a.size());
	for(vector<int>::iterator t=a.begin();t!=a.end();t++)
		printf("%d ",*t);
	return 0;
} 
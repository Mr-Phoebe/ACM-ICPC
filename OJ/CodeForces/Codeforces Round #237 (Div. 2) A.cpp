#include<iostream>
#include<cstdio> 

using namespace std;

char map[303][303];


int main()
{
	int n;
	char a,b,temp;
//	freopen("data.txt","r",stdin);
	scanf("%d\n",&n);
	bool ok=true;
	for(int i=0;i<=n;i++)
		gets(map[i]);
	if(map[0][0]==map[0][1])
		ok=false;
	for(int i=0;i<n&&ok;i++)
	{
		for(int j=0;j<n&&ok;j++)
		{
			if((i==j||i+j==n-1)&&map[i][j]!=map[0][0]||i!=j&&i+j!=n-1&&map[i][j]!=map[0][1])
			{
				ok=false;break;
			}	
		}
	}
		
	if(ok)
		cout<<"YES"<<endl;
	else	
		cout<<"NO"<<endl;
	return 0;
} 
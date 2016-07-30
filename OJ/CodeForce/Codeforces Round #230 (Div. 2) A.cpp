#include<iostream>
#include<cstdio>

using namespace std;

int a[30];

int main()
{
	char ch;
	int ans=99999;
//	freopen("data.txt","r",stdin);
	while((ch=getchar())!='\n')
	{
		int temp=(int)ch-'a';
		a[temp]++;
	}
	int n='n'-'a',i='i'-'a',e='e'-'a',t='t'-'a';

	ans=min(ans,a[i]);
	ans=min(ans,a[e]/3);
	ans=min(ans,a[t]);
	if(ans>=2)
	{
		if(a[n]<3)
			ans=0;
		else
			ans=min(ans,(a[n]-3)/2+1);
	}
	else
		ans=min(ans,a[n]/3);
	cout<<ans<<endl;
	return 0;
} 
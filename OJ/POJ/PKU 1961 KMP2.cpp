#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1000000+10;
char s[MAX];
int next[MAX];

void get_next(char *a)
{
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len)  //KMP的打表 
	{
		if(i == -1 || a[i] == a[j])
			next[++j]=++i;
		else i=next[i];
	}
	for(int i=2;i<=len;++i)       //前i个字符,i-next[i]是前i个字符的周期 
		if(i%(i-next[i]) == 0 && i/(i-next[i])>1)
			cout<<i<<' '<<i/(i-next[i])<<endl;
	return;
}

int main()
{
	int n,num=0;
	while(cin>>n&&n)
	{
		cin>>s;
		cout<<"Test case #"<<++num<<endl;
		get_next(s);
		cout<<endl;
	}
	return 0;
}
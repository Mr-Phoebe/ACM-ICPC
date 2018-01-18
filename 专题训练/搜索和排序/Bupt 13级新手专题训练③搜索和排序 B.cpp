#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

char *str[2222];

int cmp(const void* a,const void* b)
{
	return strcmp(*(char**)a,*(char**)b);
}



int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		str[i]=(char *)malloc(sizeof(char)*100);
		gets(str[i]);
		for(int j=1;j<100;j++)
			if(*(str[i]+j)==' ')
			{
				*(str[i]+j)='\0';
				break;
			} 
	}
	str[n]=(char *)malloc(sizeof(char)*100);
	qsort(str,n,sizeof(str[0]),cmp);
	int count=1;
	for(int i=0;i<n;i++)
	{
		if(strcmp(str[i],str[i+1])==0)
			count++;
		else
		{
			cout<<str[i]<<" "<<count<<endl;
			count=1;
		}
	}
	return 0;
} 
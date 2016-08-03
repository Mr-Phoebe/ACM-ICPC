#include <iostream>
#include <string.h>
using namespace std;
int n,nc;
char str[20000000],asca[125];
int hash[16000005];
int main()
{
	while(scanf("%d%d",&n,&nc)!=EOF)
	{
		scanf("%s",str);
		int i=0,j,key=0,len=strlen(str),sum,cnt=0;
		while(str[i])
		{
			if(asca[str[i]]==0)
				asca[str[i]]=key++;
			i++;
			if(key==nc)
				break;
		}
		for(i=0;i+n-1<len;i++)
		{
			sum=0;
			for(j=i;j<=i+n-1;j++)
				sum=sum*nc+asca[str[j]];
			if(hash[sum]==0) 
			{
				hash[sum]=1;
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
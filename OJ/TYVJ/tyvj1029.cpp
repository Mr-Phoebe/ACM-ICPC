#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char a[100],b[100];
	int i,j,stra,strb,ans=0;
	cin>>a>>b;
	stra=strlen(a);
	strb=strlen(b);
	for(i=stra;i>=0;i--)
		if(i<=strb-1)
			{
				for(j=0;j<i;j++)
					if(a[j]!=b[strb-i+j])
						break;
				if(j==i)
				{
				ans=ans>i? ans:i;;
				}
			}
	for(i=strb;i>=0;i--)
		if(i<=stra-1)
			{
				for(j=0;j<i;j++)
					if(b[j]!=a[stra-i+j])
						break;
				if(j==i)
				{
				ans=ans>i? ans:i;
				}
			}
		cout<<ans<<endl;
}
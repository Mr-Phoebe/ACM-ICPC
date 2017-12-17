#include<iostream>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int l,i,j;
	int a[11]={0,1,5,8,9,10,17,17,20,24,30},f[101];
	cin>>l;
	for(i=0;i<=10;i++)
		f[i]=a[i];
	for(i=1;i<=l;i++)
	{
		if(i>10)
			f[i]=f[i-1]+f[1];
		for(j=2;j<=i;i++)
			f[i]=max(f[i],f[i-j]+f[j]);
	}
	cout<<f[l]<<endl;
	
	return 0;
} 
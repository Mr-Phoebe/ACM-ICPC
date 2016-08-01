#include<iostream>
#include<cstring>

using namespace std;

int min(int a,int b)
{
	return a>b?b:a;
}

int main()
{
	freopen("dota.txt","r",stdin);
	long int n,a[301]={0},f[301][301]={0},sum[301][301]={0};
	int i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		f[i][i+1]=a[i]+a[i+1];
		for(j=i;j<=n;j++)
			sum[i][j]=sum[i][j-1]+a[j];
	}
	for (k=2;k<=n;k++)  
    {  
        for (i=1;i+k-1<=n;i++)  
        {  
            l=k+i-1;  
            f[i][l]=f[i][i]+f[i+1][l]+sum[i][i]+sum[i+1][l];  
            for (j=i+1;j<l;j++)  
                f[i][l]=min(f[i][l],f[i][j]+f[j+1][l]+sum[i][j]+sum[j+1][l]);   
        }  
    }  
	cout<<f[1][n]<<endl;
	return 0;
}


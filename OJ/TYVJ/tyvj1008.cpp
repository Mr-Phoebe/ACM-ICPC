#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,k,n,m,f[31][31];
int main()
{
    cin>>n>>m;
    memset(f,0,sizeof(f));  //f[i][j]表示求在第i号人手上，传球j次的方案数 
    f[1][0]=1;
    for(k=1;k<=m;k++)
	{
		f[1][k]=f[2][k-1]+f[n][k-1];
		for(i=2;i<=n-1;i++)
			f[i][k]=f[i-1][k-1]+f[i+1][k-1];
		f[n][k]=f[n-1][k-1]+f[1][k-1];
	}
    cout<<f[1][m]<<endl;
    return 0;
}
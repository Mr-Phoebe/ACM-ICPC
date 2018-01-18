#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
long w[1001];
long t,m,i,j,a,b;
memset(w,0,sizeof(w));
cin>>t>>m;
for (i=1; i<=m;i++)
	{
		cin>>a>>b;
		for (j=t-a; j>=0;--j)
			if (w[j]+b>w[j+a] )
				w[j+a]=w[j]+b;     
   }
 cout<<w[t]<<endl;
 return 0;  
}


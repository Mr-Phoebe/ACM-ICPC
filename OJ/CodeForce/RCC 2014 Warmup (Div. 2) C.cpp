#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib> 


using namespace std;	
		
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if(k * n > n * (n-1) / 2)
		{ puts("-1"); return 0; }
    else
    {
    	cout<<k*n<<endl;
    	for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
			printf("%d %d\n", i, (i+j)%n == 0 ? n : (i+j) % n);
    }    
    return 0;
}


#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#define maxn 110  
using namespace std;  
  
char a[maxn][maxn];  

bool found(int i,int j)
{
	if(a[i+1][j]=='#' && a[i+2][j]=='#' && a[i+1][j-1]=='#' && a[i+1][j+1]=='#')
	{  
         a[i][j]='.';  
         a[i+1][j]='.';  
         a[i+2][j]='.';  
         a[i+1][j-1]='.';  
         a[i+1][j+1]='.';
		 return  true; 
 	}
	else
		return false;
}

  
int main(void)
{  
    int n;
	cin>>n; 
	for(int i=0;i<n;i++)  
		for(int j=0;j<n;j++)  
			cin>>a[i][j];  
    for(int i=0;i<n-2;i++)  
		for(int j=1;j<n-1;j++)
			if(a[i][j]=='#'&&!found(i,j))
			{
				cout<<"NO"<<endl;  
				return 0; 
			}
     for(int i=0;i<n;i++)  
		if(a[i][0]=='#' || a[i][n-1]=='#')
		{  
			cout <<"NO"<<endl;  
			return 0;  
		}  
     for(int j=1;j<n-1;j++)  
		if(a[n-2][j]=='#' || a[n-1][j]=='#')
		{  
			cout<<"NO"<<endl;  
			return 0;  
		}
	cout<<"YES"<<endl;  
    return 0;  
}  
#include<iostream>
#include<cstring>

using namespace std; 

int i,j,k,nn,l; 
bool num[10];
bool ans;  
int a[10][10]; 

bool work(int m,int n) 
{ 
	int x=3*m+1,y=3*n+1; 
	memset(num,false,10);
	for(i=x;i<=x+2;i++)
		for(j=y;j<=y+2;j++)
			if(num[a[i][j]])
				return false;
			else
				num[a[i][j]]=true; 
	return true;
} 


int main() 
{ 
	cin>>nn; 	
	for (k=0;k<nn;k++) 
	{ 
		ans=true;
		for (i=1;i<=9;i++)
			for (j=1;j<=9;j++)
				cin>>a[i][j]; 
		for (i=1;i<=9&&ans;i++) 
		{ 
			memset(num,false,10);
			for (j=1;j<=9&&ans;j++) 
				if (num[a[i][j]])
				{
					cout<<"Wrong"<<endl;
					ans=false;
				}
				else
					num[a[i][j]]=true; 
		}
		for (i=1;i<=9&&ans;i++) 
		{
			memset(num,false,10); 
			for (j=1;j<=9&&ans;j++) 
				if (num[a[j][i]])
				{
					cout<<"Wrong"<<endl;
					ans=false;
				}
				else
					num[a[j][i]]=true; 
		}
		for (i=0;i<=2&&ans;i++) 
			for (j=0;j<=2&&ans;j++)
				if(!work(i,j))
				{
					cout<<"Wrong"<<endl;
					ans=false;
				}
		if(ans)
			cout<<"Right"<<endl; 
	} 
   return 0; 
}
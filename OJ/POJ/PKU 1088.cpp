#include<iostream>
#include<cstring> 

using namespace std;

int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
int map[111][111];
int f[111][111];
int n,m;

bool In(int x,int y)
{
	return x>=0&&x<n&&y>=0&&y<m;
}

bool judge(int x,int y,int xx,int yy)
{
	return map[x][y]>map[xx][yy];
}


int dp(int i,int j)
{
    int k;
    if(f[i][j]>1)
		return f[i][j];
    for(k=0;k<4;k++)
        if(In(i+dirx[k],j+diry[k])&&judge(i+dirx[k],j+diry[k],i,j))
        	if(f[i][j]<dp(i+dirx[k],j+diry[k])+1) 
               f[i][j]=dp(i+dirx[k],j+diry[k])+1;
    return f[i][j];

}
int main()
{
	int maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{	
			cin>>map[i][j];f[i][j]=1;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			maxn=max(maxn,dp(i,j));
	cout<<maxn<<endl;
} 
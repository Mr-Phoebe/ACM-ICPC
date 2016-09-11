#include<iostream> 

using namespace std;

int map[1000][1000];
int n,num=0;

void jud(int x,int y)
{
	if(x<n-1&&map[x+1][y]==1)
		return;
	else if(x<n-1)
		map[x+1][y]=0;
	if(x>0&&map[x-1][y]==1)
		return;
	else if(x>0)
		map[x-1][y]=0;
	if(y<n-1&&map[x][y+1]==1)
		return; 
	else if(y<n-1)
		map[x][y+1]=0;
	if(y>0&&map[x][y-1]==1)
		return;
	else if(y>0)
		map[x][y-1]=0;
	map[x][y]=1;
	num++;
	return;
}




int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			jud(i,j);
	cout<<num<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(map[i][j]==1)
				cout<<"C";
			else
				cout<<".";
		cout<<endl;
	}	
				 
	return 0;
}

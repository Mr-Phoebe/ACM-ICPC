#include <iostream>
#include <cstdlib>

using namespace std;

int map[42][42];
int r,c;//r表示行，c表示列

int findmax(int x,int y,int sum)
{
	int max=map[x-1][y],ymax=y,xmax=x-1;
	if(x==r&&y==c)
		return sum;
	if(map[x][y-1]>max)
	{
		max=map[x][y-1];
		ymax=y-1;
		xmax=x;
	}
	if(map[x][y+1]>max)
	{
		max=map[x][y+1];
		ymax=y+1;
		xmax=x;
	}
	if(map[x+1][y]>max)
	{
		max=map[x+1][y];
		ymax=y;
		xmax=x+1;
	}
	sum+=max;
	map[x][y]=0;
	return findmax(xmax,ymax,sum);
}


int main()
{

	int i,j;
	cin>>r>>c;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			cin>>map[i][j];
	cout<<findmax(1,1,map[1][1])<<endl;
    return 0;
}
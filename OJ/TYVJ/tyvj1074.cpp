#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 155
#define QSIZE 50000
#define SUBMIT

typedef struct _pos
{
	int x,y;
}pos;

char f[SIZE][SIZE];
int g[SIZE][SIZE];
pos q[QSIZE];
int head,tail,len;
int row,col;
int xx1,xx2,yy1,yy2;
int d[8][2]={
	{-1,-2},	{1,-2}, {2,-1}, {2,1},
	{1,2}, {-1,2},	{-2,1}, {-2,-1}
};

int push(int x,int y)
{
	q[tail].x=x;
	q[tail].y=y;
	if(++tail==QSIZE)
		tail=0;
	len++;
	return 0;
}

int pop(int *x, int *y)
{
	*x=q[head].x;
	*y=q[head].y;
	if(++head==QSIZE)
		head=0;
	len--;
	return 0;
}

#ifdef DISP
int disp(void)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			printf("%d%c",g[i][j],(j+1==col)?'\n':' ');
	return 0;
}
#endif

int solve(void)
{
	int x,y,xx,yy,i;
	push(xx1,yy1);
	g[xx1][yy1]=1;
	while(len>0)
	{
		pop(&x,&y);
		for(i=0;i<8;i++)
		{
			xx=x+d[i][0];
			yy=y+d[i][1];
			if(xx>=0 && xx<row && yy>=0 && yy<col && f[xx][yy]=='.' && !g[xx][yy])
			{
				push(xx,yy);
				g[xx][yy]=g[x][y]+1;
				if(xx==xx2 && yy==yy2)
				{
					len=0;
					break;
				}
			}
		}
#ifdef DISP
		disp();
#endif
	}
	return g[xx2][yy2]-1;
}

int main(void)
{
	int i,j;
#ifndef SUBMIT
	freopen("in","r",stdin);
#endif
	scanf("%d%d",&col,&row);
	for(i=0;i<row;i++)
		scanf("%s",f[i]);
	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(f[i][j]=='H')
				xx1=i,yy1=j;
			else if(f[i][j]=='K')
				xx2=i,yy2=j;
		}
	f[xx2][yy2]='.';
	printf("%d\n",solve());
	return 0;
}


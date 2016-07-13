#include<stdlib.h>
#include<stdio.h>
#define x 9999
#define max 9999

int data[11][11];
int dist[11];//记录最短路径为多少
int path[11];//记录最短路径
int kmin(int,int);
void fpath(int a[][11]);
int froute(int a[][11]);

void main()
{
     int i,j,m;
     int a[11][11]={
		{x,x,x,x,x,x,x,x,x,x,x},
		{x,x,4,2,3,x,x,x,x,x,x},
		{x,x,x,x,x,10,9,x,x,x,x},
		{x,x,x,x,x,6,7,10,x,x,x},
		{x,x,x,x,x,x,3,8,x,x,x},
		{x,x,x,x,x,x,x,x,4,8,x},
		{x,x,x,x,x,x,x,x,9,6,x},
		{x,x,x,x,x,x,x,x,5,4,x},
		{x,x,x,x,x,x,x,x,x,x,8},
		{x,x,x,x,x,x,x,x,x,x,4},
		{x,x,x,x,x,x,x,x,x,x,x}};
 
 /*    for (i=0;i<10;i++)
     {
         for(j=0;j<10;j++)
			 if(a[i][j]!=x)
				printf("%d→%d:  %d\n",i+1,j+1,a[i][j]);
         printf("\n");
     }
*/
     fpath(a);
         printf("最短路径大小为:  %d\n",dist[10]);
 
     m=froute(a);
     for(i=m-1;i>=1;i--)
         printf("最短路径经过:   %d\n",path[i]);
 }

 void fpath(int a[][11])
 {
     int i,j,k;
     dist[0]=0;
     for(i=2;i<11;i++)
     {
         k=max;
         for(j=1;j<i;j++)
             if(a[j][i]!=x&&(dist[j]+a[j][i])<k)
                     k=dist[j]+a[j][i];    
         dist[i]=k;
     }
 }

 int froute(int a[][11])
 {
     int j,b,k=1,i=9;
     path[0]=10;
     while(i>1)
     {
         for(j=i-1;j>=1;j--)
         {
             if(a[j][i]!=x)
             {
                 b=dist[i]-a[j][i];
                 if(b==dist[j])
                 {
                     path[k++]=j;
                     i=j;
                     break;
                 }
             }
 
         }
     }
         return k;
}
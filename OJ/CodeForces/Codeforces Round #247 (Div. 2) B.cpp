#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 110
#define ll long long

using namespace std;

int a[MAXN][MAXN];
int b[MAXN];

int main(void)
{
    for(int i=1;i<=5;i++)
	{
        for(int j=1;j<=5;j++) 
            scanf("%d", &a[i][j]);
        b[i]=i;
    }

    ll sum=a[b[1]][b[2]]+a[b[2]][b[1]]+a[b[2]][b[3]]+a[b[3]][b[2]]+2*a[b[3]][b[4]]+2*a[b[4]][b[3]]+2*a[b[4]][b[5]]+2*a[b[5]][b[4]];
    ll bestsum = sum;
    while(next_permutation(b+1, b+6))
	{
        sum=a[b[1]][b[2]]+a[b[2]][b[1]]+a[b[2]][b[3]]+a[b[3]][b[2]]+2*a[b[3]][b[4]]+2*a[b[4]][b[3]]+2*a[b[4]][b[5]]+2*a[b[5]][b[4]];
      	bestsum=max(sum,bestsum);
    }
    printf("%d\n",bestsum);
    return 0;
}
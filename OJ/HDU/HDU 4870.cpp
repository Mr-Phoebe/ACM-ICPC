#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define LL long long
#define _LL __int64
#define eps 1e-12
#define PI acos(-1.0)
using namespace std;

const int maxn = 231;

double a[235][235],p;
int equ,var;
double x[235];
int flag[235][235];
int cnt;

double Gauss()
{
    int row,col,max_r;
    int i,j;

    row = col = 0;
    while(row < equ && col < var)
    {
        max_r = row;
        for(i = row+1; i < equ; i++)
            if(fabs(a[i][col])-fabs(a[max_r][col]) > eps)
                max_r = i;

        if(max_r != row)
        {
            for(j = col; j <= var; j++)
                swap(a[row][j],a[max_r][j]);
        }
        if(fabs(a[row][col]) < eps)
        {
            col++;
            continue;
        }

        for(i = row+1; i < equ; i++)
        {
            if(fabs(a[i][col]) > eps)
            {
                double t = a[i][col]/a[row][col];
                a[i][col] = 0.0;

                for(j = col+1; j <= var; j++)
                    a[i][j] -= a[row][j]*t;
            }
        }
        row++;
        col++;
    }

    for(i = equ-1; i >= 0; i--)
    {
        if(fabs(a[i][i]) < eps) continue;
        double tmp = a[i][var];
        for(j = i+1; j < var; j++)
            tmp -= a[i][j]*x[j];
        x[i] = tmp/a[i][i];
    }
    return x[0];
}

int main()
{
    cnt = 0;
    memset(flag,-1,sizeof(flag));
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j <= i; j++)
            flag[i][j] = cnt++;
    }
    while(~scanf("%lf",&p))
    {
        equ = var = 210;
        int x;
        memset(a,0,sizeof(a));
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < i; j++)
            {
                x = flag[i][j];
                a[x][x] = 1;
                a[x][210] = 1;
                a[x][flag[i][max(0,j-2)]] -= (1-p);
                a[x][flag[i][j+1]] -= p;
            }
            x = flag[i][i];
            a[x][x] = 1;
            a[x][210] = 1;
            a[x][flag[i][max(0,i-2)]] -= (1-p);
            a[x][flag[i+1][i]] -= p;
        }
        for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<cnt;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		} 
        printf("%.6lf\n", Gauss());
    }
    return 0;
}

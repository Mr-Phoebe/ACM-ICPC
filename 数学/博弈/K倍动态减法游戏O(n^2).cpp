#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
//-----------------------------------------------------------------------

const int INF=0x3f3f3f3f;
int np[30][30];
int f[50];
int n,m=20,k;


int main()
{
	while(read(k))
	{
		np[0][m]=1;
		np[1][1]=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<m-i;j++)
				for(int s=1;s<=min(i,k*j);s++)
					if(!np[i-s][s] || i-s==0)
						np[i][j]=1;

		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=i;j++)
				cout<<np[i][j]<<" ";
			cout<<endl;
		}
		f[0]=m;
		f[1]=1;//first 1

		for(int i=2;i<=m;i++)
        {
            f[i]=INF;
            for(int j=1;j<=i;j++)
                if( f[i-j]>j )// np[i-j,j]==0
                    f[i]=min(f[i],j/k);


        }
        for(int i=1;i<=m;i++)
            cout<<f[i]<<" ";
        cout<<endl;
	}
	return 0;
}

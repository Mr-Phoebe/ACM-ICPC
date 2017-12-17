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

int np[20][20];
int n,m=10,k; 


int main()
{
	while(read(k))
	{
		np[0][m]=1;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<m-i;j++)
				for(int s=1;s<=min(i,k*j);s++)
					if(!np[i-s][s])
						np[i][j]=1;
			np[i][m-i]=1;
		}	
		for(int i=m;i>=0;i--)
		{
			for(int j=1;j<=m-i;j++)
				cout<<np[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
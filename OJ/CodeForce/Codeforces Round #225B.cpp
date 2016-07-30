#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X,Y) push_back(X,Y)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int a[1000][100];
int main()
{
     int n,m,k;
     while(cin>>n>>m>>k)
     {
         for(int i = 0; i < n; i++)
      	   for(int j = 0; j < m; j++)
             cin>>a[i][j];
         //if(k==0) //ascending
         cout<<m*(m-1)/2<<endl;
         for(int i = 0; i < m; i++)
         	for(int j = 0; j < m-i-1; j++)
         	{
         	    if(k==0)
        	         cout<<j+1<<' '<<j+2<<endl;
        	     else
        	         cout<<j+2<<' '<<j+1<<endl;
        	 }
     }
     return 0;
 }
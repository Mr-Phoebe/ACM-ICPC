#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

#define eps 1e-8
const double pi=acos(-1.0);
typedef long long LL;
const int Max=10100;
const int INF=1000000007;


int num[Max];
int n,m;
int main()
{

  while(scanf("%d%d",&n,&m)==2)
  {
      for(int i=1;i<=n;i++)
        scanf("%d",num+i);
        int ans=0;
      for(int i=0;i<m;i++)
      {
          int a,b;scanf("%d%d",&a,&b);
          ans+=min(num[a],num[b]);
      }
      cout<<ans<<endl;
  }
   return 0;
}

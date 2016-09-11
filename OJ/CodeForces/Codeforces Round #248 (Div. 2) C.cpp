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

const int MAXN=100100;  
typedef long long int ll;  
  
int n,m;  
ll a[MAXN];  
vector<int> near[MAXN];  
  
int main()  
{  
    scanf("%d %d",&n,&m); 
    for(int i=0;i<m;i++)  
        scanf("%d",&a[i]);  
    ll cur=0,orz;  
    for(int i=0;i<m-1;i++)   
        cur+=abs(a[i+1]-a[i]);   
    orz=cur;  
    for(int i=0;i<m;i++)  
    {  
        if(i-1>=0&&a[i-1]!=a[i])  
            near[a[i]].push_back(a[i-1]);  
        if(i+1<m&&a[i]!=a[i+1])  
            near[a[i]].push_back(a[i+1]);  
    }  
    for(int i=1;i<=n;i++)  
    {  
        int s=near[i].size();  
        if(s)  
        {  
            sort(near[i].begin(),near[i].end());  
            ll change=0;int mid=near[i][s/2];  
            for(int j=0;j<s;j++)  
                change+=abs(near[i][j]-mid)-abs(near[i][j]-i);   
            cur=min(cur,orz+change);  
        }  
    }  
    printf("%I64d\n",cur); 
    return 0;  
}  
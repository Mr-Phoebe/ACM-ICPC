#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;
int a[100005];
int main()
{
    int T,n;
    scanf("%d",&T);
    rep(cas,T)
    {
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int pre = 0, flag = 0, num = 0;
        for(int i=0;i<n;i++)
        {
            if(abs(pre-a[i])>3 || (pre==a[i] && pre!=1))
            {
                flag = 1;
                break;
            }
            else if((pre==1 && a[i]==2) || (pre==2 && a[i]==1))
            {
                num++;
            }
            pre = a[i];
        }
        int ret = 0;
        if(flag)
            ret = 0;
        else
            ret = num+1;
        if(a[n-1] != 0)
            ret *= 2;
        printf("Case #%d: %d\n",cas+1,ret);
    }
}






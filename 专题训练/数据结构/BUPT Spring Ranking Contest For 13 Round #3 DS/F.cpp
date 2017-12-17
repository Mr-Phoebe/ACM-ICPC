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

const int MAXN=2010;

int a[MAXN],b[MAXN],n,m;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        m--;
        sort(a,a+n);
        priority_queue< int>q;
        while(m--)
        {
            for(int i=0;i<n;i++)
                scanf("%d",&b[i]);
            sort(b,b+n);
            for(int i=0;i<n;i++)//第一行作为比较
                q.push(a[i]+b[0]);
            for(int i=1;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    if(a[j]+b[i]>q.top())
                        break;
                    q.pop(),q.push(a[j]+b[i]);
                }
            for(int i=0;i<n;i++)
            {
                a[i]=q.top();
                q.pop();
            }
            sort(a,a+n);
        }
        for(int i=0;i<n;i++)
        {
            printf("%d",a[i]);
            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}

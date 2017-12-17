//By LH
#pragma warning(disable:4996)
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int n, ans;
int a[200005], pos[200005], f1[200005], f2[200005], d[200005];

int cmp(int i, int j)
{
    return a[i] < a[j];
}

int BinSearch(int key, int* d, int low, int high)
{
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(key>d[mid] && key<=d[mid+1])
            return mid;
        else if(key>d[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}

void LIS(int* q, int n, int* d, int* p)
{
    int i,j;
    d[1] = q[1]; p[1] = 1;
    int len = 1;
    for(i = 2; i <= n; i++)
    {
        if(d[len]<q[i])
            j = ++len;
        else
            j = BinSearch(q[i],d,1,len) + 1;
        p[i] = j;
        d[j] = q[i];
    }
    for (int i =  2; i <= n; i++)
    if (p[i]<p[i-1]) p[i] = p[i-1];
}

int main()
{
    freopen("improvements.in","r",stdin);
    freopen("improvements.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pos[i] = i;
    }
    sort(pos+1, pos+n+1, cmp);
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    LIS(pos, n, d, f1);
    for (int i = 1; i <= n/2; i++) swap(pos[i], pos[n-i+1]);
    LIS(pos, n, d, f2);
    for (int i = 1; i <= n/2; i++) swap(f2[i], f2[n-i+1]);
    ans = 1;
    for (int i = 1; i <= n+1; i++)
    {
        int tmp1, tmp2;
        if (i == 1) tmp1 = 0;
        else tmp1 = f1[i-1];
        if (i == n+1) tmp2 = 0;
        else tmp2 = f2[i];
        if (tmp1+tmp2 > ans) ans = tmp1+tmp2;
    }
    printf("%d\n", ans);
    return 0;
}
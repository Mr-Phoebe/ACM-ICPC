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

void read(int &x)
{
    x=0;
    ch=getchar();
    while (ch<=32) ch=getchar();
    while (ch>32) x=x*10+ch-48,ch=getchar();
}

int n;
int a[100005];
int fl[100005];
int fr[100005];

int main()
{
    read(n);
    int i;
    for (i=1;i<=n;i++) {
        read(a[i]);
    }
    int ans=1;
    fl[1]=1;
    for (i=2;i<=n;i++) {
        if (a[i]>a[i-1]) {
            fl[i]=fl[i-1]+1;
        } else {
            fl[i]=1;
        }
        if (fl[i]>ans) ans=fl[i];
    }
    fr[n]=1;
    for (i=n-1;i>=1;i--) {
        if (a[i]<a[i+1]) {
            fr[i]=fr[i+1]+1;
        } else {
            fr[i]=1;
        }
        if (fr[i]>ans) ans=fr[i];
    }
    for (i=2;i<n;i++) {
        if (a[i+1]-1>a[i-1]) {
            int tmp=fl[i-1]+fr[i+1]+1;
            if (tmp>ans) ans=tmp;
        }
    }
    for (i=1;i<n;i++) {
        if (fl[i]+1>ans) ans=fl[i]+1;
    }
    for (i=2;i<=n;i++) {
        if (fr[i]+1>ans) ans=fr[i]+1;
    }
    printf("%d\n",ans);
}
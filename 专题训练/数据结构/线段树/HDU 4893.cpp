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
#define eps 1e-9
#define INF 0x3f3f3f3f
#define ll long long
#define lowbit(x) (x)&(-x)

using namespace std;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int N=100010;
int n,m;
ll sum[N*4],sf[N*4];
int c[N*4];
ll fi[55];
ll find(ll data)
{
    if(data<=1)
        return 1;
    int tmp=lower_bound(fi,fi+52,data)-fi;
    if(fabs(data-fi[tmp])<fabs(data-fi[tmp-1]))
        return fi[tmp];
    else
        return fi[tmp-1];
}
void update(int idx,int start,int end)
{
    if(start!=end)
    {
        if(c[idx])
            c[idx*2]=c[idx*2+1]=1;
        sum[idx]=0;
        if(c[idx*2])
            sum[idx]+=sf[idx*2];
        else
            sum[idx]+=sum[idx*2];
        if(c[idx*2+1])
            sum[idx]+=sf[idx*2+1];
        else
            sum[idx]+=sum[idx*2+1];
        sf[idx]=sf[idx*2]+sf[idx*2+1];
    }
    if(c[idx])
        sum[idx]=sf[idx],c[idx]=0;
}

ll getsum(int idx,int start,int end,int l,int r)
{
    update(idx,start,end);
    int mid=start+(end-start)/2;
    if(l<=start&&end<=r)
        return sum[idx];
    else if(r<=mid)
        return getsum(idx*2,start,mid,l,r);
    else if(mid+1<=l)
        return getsum(idx*2+1,mid+1,end,l,r);
    else
        return getsum(idx*2,start,mid,l,mid)+getsum(idx*2+1,mid+1,end,mid+1,r);
}


void inser(int idx,int start,int end,int l,int r,ll data)
{
    int mid=(start+end)/2;
    update(idx,start,end);
    if(l<=start&&end<=r)
    {
        sum[idx]+=data;
        sf[idx]=find(sum[idx]);
        c[idx]=0;
    }
    else if(r<=mid)
        inser(idx*2,start,mid,l,r,data);
    else if(mid+1<=l)
        inser(idx*2+1,mid+1,end,l,r,data);
    else
    {
        inser(idx*2,start,mid,l,mid,data);
        inser(idx*2+1,mid+1,end,mid+1,r,data);
    }
    update(idx,start,end);
}

void modify(int idx,int start,int end,int l,int r)
{
    int mid=(start+end)/2;
    if(l<=start&&end<=r)c[idx]=1;
    else if(r<=mid)modify(idx*2,start,mid,l,r);
    else if(mid+1<=l)modify(idx*2+1,mid+1,end,l,r);
    else
    {
        modify(idx*2,start,mid,l,mid);
        modify(idx*2+1,mid+1,end,mid+1,r);
    }
    update(idx,start,end);
}

int main()
{
    int i,j,k,tt,s;
    fi[0]=fi[1]=1;
    for(i=2; i<=52; i++)
        fi[i]=fi[i-1]+fi[i-2];
    while(read(n)&&read(m))
    {
        for(s=1; s<=n; s++)
            inser(1,1,n,s,s,0);
        for(tt=0; tt<m; tt++)
        {
            read(i),read(j),read(k);
            if(i==1)
                inser(1,1,n,j,j,k);
            else if(i==2)
            {
                write(getsum(1,1,n,j,k));putchar('\n');
            }

            else
                modify(1,1,n,j,k);
        }
        memset(sum,0,sizeof(sum));
        memset(c,0,sizeof(c));
        memset(sf,0,sizeof(sf));
    }
    return 0;
}

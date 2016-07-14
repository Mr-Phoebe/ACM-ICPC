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
#define EPS 1e-10
#define INF 0x3f3f3f3f
#define ll long long
 
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
template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n) {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
 
 
//-----------------------------------------------------------------------
 
const int MAXN=200000;
 
void radix(int *str,int *a,int *b,int n,int m)
{
    static int count[200000];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;++i)
        ++count[str[a[i]]];
    for(int i=1;i<=m;++i)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;--i)
        b[--count[str[a[i]]]]=a[i];
}
 
void suffix_array(int *str,int *sa,int n,int m)
{
    static int rank[200000],a[200000],b[200000];
    for(int i=0;i<n;i++)
        rank[i]=i;
    radix(str,rank,sa,n,m);
    rank[sa[0]]=0;
    for(int i=1;i<n;i++)
        rank[sa[i]]=rank[sa[i-1]]+(str[sa[i]]!=str[sa[i-1]]);
    for(int i=0;1<<i <n;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[j]=rank[j]+1;
            b[j]=j +(1<<i)>=n? 0:rank[j+(1<<i)] +1;
            sa[j]=j;
        }
        radix(b,sa,rank,n,n);
        radix(a,rank,sa,n,n);
        rank[sa[0]]=0;
        for(int j=1;j<n;j++)
        {
            rank[sa[j]]=rank[sa[j-1]]+(a[sa[j-1]]!=a[sa[j]]||b[sa[j-1]]!=b[sa[j]]);
        }
    }
}
 
string duplicate_substr(string str)
{
    string rev;
    static int s[3000],sa[3000],rank[3000],h[3000];
    int n=str.length();
    copy(str.begin(),str.end(),s);
    suffix_array(s,sa,n,256);
    for(int i=0;i<n;++i)
        rank[sa[i]]=i;
    int k=0;
    int ans1=0,pos1=0;
    for(int i=0;i<n;i++)
    {
        k= k==0? 0:k-1;
        while(rank[i]>0&&s[i+k]==s[sa[rank[i]-1]+k])
            ++k;
        h[rank[i]]=k;
        if(h[rank[i]]>ans1)
        {
            ans1=h[rank[i]];
            pos1=i;
        }
    }
    return str.substr(pos1,ans1);
}
 
int main()
{
    int T;
    read(T);
    while(T--)
    {
        string s;
        cin>>s;
        s=duplicate_substr(s);
        printf("%d\n",s.length());
    }
    return 0;
}
#include <bits/stdc++.h>

#define MAXN 1005
#define eps 1e-14
#define MOD 1000000009
#define INF 1000000009

#define test

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define vecfor(iter,a) for(vector<int>::iterator iter=a.begin();iter!=a.end();iter++)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define LL long long

/*author birdstorm*/
using namespace std;
const double pi=acos(-1.0);

template<class T>
inline bool read(T &n){
    T x=0, tmp=1; char c=getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c=getchar();
    if(c == EOF) return false;
    if(c == '-') c=getchar(), tmp=-1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c=getchar();
    n=x*tmp;
    return true;
}

template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n=-n;
    }
    int len=0,data[20];
    while(n) {
        data[len++]=n%10;
        n /= 10;
    }
    if(!len) data[len++]=0;
    while(len--) putchar(data[len]+48);
}
LL a[MAXN];
double vis[MAXN][MAXN];
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    int n, m;
    while(read(n)){
        double dov=1.0;
        For(i,0,n){
            read(a[i]);
        }
        For(i,0,n) For(j,0,128){
            vis[i][j]=0.0;
        }
        rep(i,1,a[0]) vis[0][i]=1.0/(a[0]*1.0);
        For(i,1,n){
            For(j,0,128){
                    rep(k,1,a[i]){
                        vis[i][j^k]+=vis[i-1][j]/(a[i]*1.0);
                    }
            }
        }
        printf("%.6f\n",vis[n-1][0]);
    }
    return 0;
}

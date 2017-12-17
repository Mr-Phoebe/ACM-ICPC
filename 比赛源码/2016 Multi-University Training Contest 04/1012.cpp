#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include<complex>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const int N = 101010;
int T,n,a[N],b[N];
#define lb(x)(x&(-x))
struct Fenwick{
    int a[N],l;
    void add(int x){
        for(int i=x;i<=l;i+=lb(i)) a[i]++;
    }
    int sum(int x){
        int r=0;for(int i=x;i>=1;i-=lb(i)) r+=a[i];return r;
    }
}f;

void main2(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",a + i);
    f.l = n;fill(f.a,f.a+n+1,0);
    for(int i=n;i>=1;--i) b[a[i]] = i + f.sum(a[i]) - min(a[i] , i) , f.add(a[i]);
    rep(i,1,n+1) printf("%d%c",b[i]," \n"[i==n]);
}

int main(){
  //  freopen("in", "r", stdin);
 //   freopen("out", "w", stdout);
    db t1 = clock();
    scanf("%d",&T);
    rep(i,1,T+1) printf("Case #%d: ",i) , main2();
  //  cerr << (clock() - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}

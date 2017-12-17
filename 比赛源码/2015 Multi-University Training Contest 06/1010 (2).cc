#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2048,p=1e9+7;

ll pm(ll a,int n=p-2){
  ll r=1;
  for(;n;n>>=1,a=a*a%p)if(n&1)r=r*a%p;
  return r;
}
int fac[N],ifac[N];
int sol(const int n,const int m){
  static ll a[N];
  const int N=(n&1)+n,d=pm(2,p-1-m);
  fill(a,a+N+1,0);
  for(int i=0,h=(m+1>>1);i<h;++i){
    ll c = ll(d<<1)*fac[m]%p*ifac[i]%p*ifac[m-i]%p;
    const int u=(m-(i<<1))*(m-(i<<1));
    for(int j=0;j<=N;j+=2,c=c*u%p)
      a[j]=a[j]+c;
  }
  if(!(m&1))
    a[0]+=ll(d)*fac[m]%p*ifac[m>>1]%p*ifac[m>>1];
  for(int j=1;j<=n;j+=2)
    a[j]=a[j+1];
  int res = 0;
  for(int j=n,v=1;j;--j,v=v*(ll)m%p)
    res=(res+a[j]%p*(n+1-j)%p*v)%p;
  return (res+p)%p;
}
int main(){
  for(int i=fac[0]=ifac[0]=1;i<N;++i)
    ifac[i]=pm(fac[i]=fac[i-1]*ll(i)%p);
  int T,n,m;
  for(scanf("%d",&T);T--;printf("%d\n",sol(n,m)))
    scanf("%d%d",&n,&m);
}
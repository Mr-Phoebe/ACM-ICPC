#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1024000;
char s[N];
int p[N],t[N],a[N],b[N],u[N];
ll c[N];
void sol(){
  int l=strlen(gets(s+1));
  if(isspace(s[l]))l--; 
  int k=0;
  fill(a+1,a+l+2,0);
  fill(b,b+l+1,0);
  for(int i=1;i<=l;++i)
  if(s[i]=='('){
    u[i]=t[k];
    t[++k]=i;
  }else if(k){
    p[p[i]=t[k--]]=i;
    a[p[i]]=1;
    b[i]=b[p[i]-1]+1;
  }else p[i]=0;
  for(;k;)u[t[k]]=p[t[k--]]=0;
  for(int i=l;i;--i)if(a[i])
    b[i]+=a[i]=1+a[p[i]+1];
  fill(c,c+l+1,0);
  for(int i=1;i<=l;++i)
  if(s[i]=='(' && p[i])
    c[p[i]]=c[i]=(u[i]?c[u[i]]:0)+b[i]*(ll)b[p[i]];
  ll ret(0), mod=1e9+7;
  for(int i=1;i<=l;++i) ret += c[i] % mod * i % mod;
  printf("%lld\n", ret);
}
int main(){
  int T;
  for(sscanf(gets(s),"%d",&T);T--;sol());
}
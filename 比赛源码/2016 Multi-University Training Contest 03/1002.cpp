#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 1005
#define LL long long

int n,c[N];
LL tot,v;
double ans;

int main(){
	while(scanf("%d",&n)^-1){
		rep(i,1,n) scanf("%d",c+i);
		if(n==1){printf("%.6lf\n",(double)c[1]);continue;}
		v=(LL)(n-1)*n*(2*n-1)/6-(LL)n*(n-1)/2;
		tot=0;
		ans=0;
		if(n>2){
			rep(i,2,n-1) tot+=v*c[i];
			ans+=(double)tot/(n-2)/(n-1)/n;
		}
		v=(LL)n*(n-1)/2;
		ans+=(double)(v*c[1]+v*c[n])/(n-1)/n;
		printf("%.9lf\n",ans);
	}
}


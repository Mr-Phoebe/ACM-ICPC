#include<stdio.h>
#include<algorithm>
#include<assert.h>
#include<cmath>
using namespace std;
const double phi=(1+sqrt(5.))/2.;
const double phi2=phi*phi;
int F[1005],opt,T,n,m,x,y,i,ans;
int ok(){
	if (opt==1) return (n&1^1)||(m&1^1);
	if (opt==2) return (n!=m);
	if (opt==3){
		if (n<m) swap(n,m);
		if (n%3==0&&m==n-1) return 1;
		if (n==m&&n%3==1) return 0;
		return 2;
	}
	n--;m--;
	return F[n]==m?0:1;
}
int main(){
	for (i=1;;i++){
		x=i*phi;
		y=i*phi2;
		if (y>1000) break;
		F[x]=y;
	}
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&opt,&n,&m);
		if (n>m) swap(n,m);
		assert(n>1);assert(m<=1000);
		ans=ok();
		if (ans==1) putchar('B');
		else if (ans==0) putchar('G');
		else putchar('D');
		puts("");
	}
}

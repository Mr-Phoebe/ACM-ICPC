#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
LL n,a[50],p[50],l,r,Cas=0,T;
LL Q_mul(LL a,LL b,LL Mod){
	LL ret;  
    for(ret=0; b; b>>=1,a=(a+a)%Mod) if(b&1) ret=(ret+a)%Mod;
    return ret; 
}
LL Ex_Gcd(LL a,LL b,LL &x,LL &y){
	LL d;
	if(b==0){
		x=1,y=0;
		return a;
	}
	d=Ex_Gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
LL Bitcount(LL x){
	return x?Bitcount(x>>1)+(x&1):0;
}
LL CRT(LL a[],LL p[],LL M,LL k){
	LL ans=0;
	for(int i=0; i<=k; ++i){
		LL x,y,d,Mi=M/p[i];
		d=Ex_Gcd(p[i],Mi,x,y);
		ans=(ans+Q_mul(Q_mul(y,Mi,M),a[i],M))%M;
	}
	return (ans+M)%M;
}
LL Get_ans(LL x){
	LL ta[50],tp[50],t,i,num,top,j,ans=0;
	if(x==0) return 0;
	for(ta[0]=0,tp[0]=7,i=1; i<(1<<n); ++i){
		num=Bitcount(i);
		for(t=7,top=j=0; j<n; ++j)
			if(i&(1<<j)){
				ta[++top]=a[j];
				tp[top]=p[j];
				t*=p[j];
			}
		LL res=CRT(ta,tp,t,top);
		if(x<res) continue;
		if(num%2) ans-=(x-res)/t+1;
		else ans+=(x-res)/t+1;
		//printf("%I64d\n",ans);
	}
	return ans+x/7;
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(Cas=1; Cas<=T; ++Cas){
		scanf("%I64d%I64d%I64d",&n,&l,&r);
		for(int i=0; i<n; ++i) scanf("%I64d%I64d",&p[i],&a[i]);
		printf("Case #%I64d: %I64d\n",Cas,Get_ans(r)-Get_ans(l-1));
	}
	return 0;
}

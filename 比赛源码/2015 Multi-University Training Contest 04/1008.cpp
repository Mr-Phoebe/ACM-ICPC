#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int flag,n,K,ans,A[110000],num;
void check(int L,long long K){
	if (K==0){
		for (int i=1;i<=L;i++) A[++num]=1;
		return;
	}
	int l=1,r=L+1,ans;
	while (l<r){
		int mid=l+r>>1;
		if (1ll*mid*(mid-1)<=K){
			ans=mid; l=mid+1;
		} else r=mid;
	}
	int mid=ans;
	while (K>=1ll*(mid-1)*mid){
		K-=1ll*(mid-1)*mid; L-=mid; A[++num]=mid;
	}
	check(L,K);
}		
int main(){
//	freopen("data.in","r",stdin);
//	freopen("dataa.out","w",stdout);
	while (scanf("%d",&K)!=EOF){
		int l=0; num=0;
		if (K<=100000){
			cout<<K<<endl; for (int i=1;i<=K;i++) printf("1 "); cout<<endl; continue;
		}
		while (l*(l+1)<K*2) l++; check(l,1ll*l*(l+1)-K*2); printf("%d\n",l);
		for (int i=1;i<=num;i++) for (int j=1;j<=A[i];j++) printf("%d ",i); cout<<endl;
	}
	return 0;
}

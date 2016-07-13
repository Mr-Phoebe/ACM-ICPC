#include<cstdio>
#include<cstring>
#include<cmath>
#define LL __int64
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
const int N = 200007;
int min[N][20];
int max[N][20];
int queryMin(int l,int r){
	int k=log2((double)(r-l+1));
	return Min(min[l][k],min[r-(1<<k)+1][k]);
}
int queryMax(int l,int r){
	int k=log2((double)(r-l+1));
	return Max(max[l][k],max[r-(1<<k)+1][k]);
}
int calc(int l,int r){
	int k=log2((double)(r-l+1));
	int MAX=Max(max[l][k],max[r-(1<<k)+1][k]);
	int MIN=Min(min[l][k],min[r-(1<<k)+1][k]);
	return MAX-MIN;
}
char filein[]={"9.in"};
char fileot[]={"9.out"};
int main(){
//	for(int t=0;t<10;++t){
//	filein[0]=t+'0';
//	fileot[0]=t+'0';
//	freopen(filein,"r",stdin);
//	freopen(fileot,"w",stdout);
	int T;
	int n,k,i,j,p;
	LL ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i){
			scanf("%d",&j);
			min[i][0]=max[i][0]=j;
		}
		for(j=1;(1<<j)<=n;++j)
		for(i=1;i+(1<<j)-1<=n;++i){
			p=(1<<(j-1));
			min[i][j]=Min(min[i][j-1],min[i+p][j-1]);
			max[i][j]=Max(max[i][j-1],max[i+p][j-1]);
		}
		int l,r;
		ans=0;
		for(i=1;i<=n;++i){
			l=i,r=n;
			while(l+1<r){
				p=(l+r)>>1;
				if(calc(i,p)<k){
					l=p;
				}
				else{
					r=p;
				}
			}
			if(calc(i,r)<k){
				p=r;
				ans=ans+(LL)(r-i+1);
			}
			else{
				p=l;
				ans=ans+(LL)(l-i+1);
			}
		}
		printf("%I64d\n",ans);
	}
//	fclose(stdin);
//	fclose(stdout);
//	}
	return 0;
}

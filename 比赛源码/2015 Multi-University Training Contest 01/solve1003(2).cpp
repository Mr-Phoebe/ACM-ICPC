#include<cstdio>
#include<cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 100007
int n;
int a[N];
int dep[N];
int pre[N];
int f[N][102];
int g[N][102];
int mf[N][102];
int mg[N][102];
int que[N],head,tail;
int et,ehead[N];
struct Edge{
	int t,next;
}	e[N<<1];
inline void addEdge(int u,int v){
	e[et].t=v,e[et].next=ehead[u],ehead[u]=et++;
	e[et].t=u,e[et].next=ehead[v],ehead[v]=et++;
}
int main(){
	int i,j,k,t,d,r,u,v,u2;
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	while(~scanf("%d",&n)){
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		et=0,memset(ehead,-1,sizeof(ehead));
		for(i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			addEdge(u,v);
		}
		memset(g,-1,sizeof(g));
		memset(f,-1,sizeof(f));
		memset(mg,-1,sizeof(g));
		memset(mf,-1,sizeof(f));
		head=0,tail=1;
		que[1]=1,pre[1]=-1;
		while(head<tail){
			v=que[++head];
			dep[v]=0;
			for(i=ehead[v];i!=-1;i=e[i].next)
			if((u=e[i].t)!=pre[v]){
				pre[u]=v;
				que[++tail]=u;
			}
		}
		while(tail>0){
			v=que[tail--];
//			printf("bfs %d\n",v);
			if(pre[v]>=0){
				dep[pre[v]]=MAX(dep[pre[v]],dep[v]+1);
			}
			if(dep[v]==0){
				if(a[v]>=0){
					f[v][a[v]]=1;
					for(i=0;i<a[v];++i) mf[v][i]=-1;
					for(i=a[v];i<=100;++i) mf[v][i]=1;
				}
				g[v][0]=0;
				for(i=0;i<=100;++i) mg[v][i]=0;
				continue;
			}
			// g[v]
			for(i=0;i<=MIN(100,dep[v]);++i){
				g[v][i]=0;
				for(j=ehead[v];j!=-1;j=e[j].next)
				if((u=e[j].t)!=pre[v]){
					t=mg[u][i-1];
//					for(k=0;k<i;++k)
//					if(g[u][k]!=-1){
//						if(t==-1 || t>g[u][k]){
//							t=g[u][k];
//						}
//					}
					d=mf[u][100];
//					for(k=0;k<=100;++k)
//					if(f[u][k]!=-1){
//						if(d==-1 || d>f[u][k]){
//							d=f[u][k];
//						}
//					}
					if(t==-1 && d==-1){
						g[v][i]=-1;
						break;
					}
					if(t==-1) t=N;
					if(d==-1) d=N;
					g[v][i]+=MIN(t,d);
				}
				if(g[v][i]==-1) break;
			}
			// f[v]
			// pick v
			if(a[v]>=0){
				f[v][a[v]]=1;
				for(i=ehead[v];i!=-1;i=e[i].next)
				if((u=e[i].t)!=pre[v]){
					t=mf[u][100];
//					for(j=0;j<=100;++j)
//					if(f[u][j]!=-1){
//						if(t==-1 || t>f[u][j]){
//							t=f[u][j];
//						}
//					}
					d=-1;
					if(a[v]>=1) d=mg[u][a[v]-1];
//					for(j=0;j<a[v];++j)
//					if(g[u][j]!=-1){
//						if(d==-1 || d>g[u][j]){
//							d=g[u][j];
//						}
//					}
					if(t==-1 && d==-1){
						f[v][a[v]]=-1;
						break;
					}
					if(t==-1) t=N;
					if(d==-1) d=N;
					f[v][a[v]]+=MIN(t,d);
				}
			}
			// not pick v
			for(i=ehead[v];i!=-1;i=e[i].next)
			if((u=e[i].t)!=pre[v]){
				for(j=1;j<=100;++j)
				if(f[u][j]!=-1){
					// supply j-1
					int mini=0;
					for(k=ehead[v];k!=-1;k=e[k].next)
					if((u2=e[k].t)!=pre[v] && u2!=u){
						t=mf[u2][100];
//						for(r=0;r<=100;++r)
//						if(f[u2][r]!=-1){
//							if(t==-1 || t>f[u2][r]){
//								t=f[u2][r];
//							}
//						}
						d=-1;
						if(j-2>=0) d=mg[u2][j-2];
//						for(r=0;r<j-1;++r)
//						if(g[u2][r]!=-1){
//							if(d==-1 || d>g[u2][r]){
//								d=g[u2][r];
//							}
//						}
						if(t==-1 && d==-1){
							mini=-1;
							break;
						}
						if(t==-1) t=N;
						if(d==-1) d=N;
						mini+=MIN(t,d);
					}
					if(mini!=-1){
						if(f[v][j-1]==-1 || f[v][j-1]>f[u][j]+mini){
							f[v][j-1]=f[u][j]+mini;
						}
					}
				}
			}
			mf[v][0]=f[v][0],mg[v][0]=g[v][0];
			for(i=1;i<=100;++i){
				mf[v][i]=mf[v][i-1];
				if(f[v][i]!=-1){
					if(mf[v][i]==-1 || mf[v][i]>f[v][i]) mf[v][i]=f[v][i];
				}
				mg[v][i]=mg[v][i-1];
				if(g[v][i]!=-1){
					if(mg[v][i]==-1 || mg[v][i]>g[v][i]) mg[v][i]=g[v][i];
				}
			}
		}
		int ans=-1;
		for(i=0;i<=100;++i)
		if(f[1][i]!=-1){
			if(ans==-1 || ans>f[1][i]){
				ans=f[1][i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

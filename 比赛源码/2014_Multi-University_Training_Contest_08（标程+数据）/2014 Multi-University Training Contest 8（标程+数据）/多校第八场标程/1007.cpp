#include <cstdio>
#include <ctime>
#define rep(i,a,n) for (int i=a;i<n;i++)
const int N=510;
int p,__;
int x[N][N],go[N],ch[N];
inline int getint() {
	int ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}
int main() {
	while (1) {
		p=getint();
		if (p==0) break;
		rep(i,0,p) rep(j,0,p) (x[i][j]=getint()),getint();
		printf("Case #%d:",++__);
		if (p==2) { printf(" %d %d\n",x[0][0],1-x[0][0]); continue;}
		else {
			rep(i,0,p) ch[i]=-1;
			rep(i,0,p) {
				int cnt=0;
				rep(j,0,p) if (ch[x[i][j]]!=i) ch[x[i][j]]=i,cnt++;
				if (cnt==p-1) {
					go[p-1]=i;
					for (int j=p-1;j;j--) go[j-1]=x[i][go[j]];
					break;
				}
			}
			rep(i,0,p) printf(" %d",go[i]); puts("");
		}
	} 
}

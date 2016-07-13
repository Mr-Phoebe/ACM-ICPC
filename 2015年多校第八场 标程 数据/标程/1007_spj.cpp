#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=505;
FILE	*Finn;
int a[N][N],b[N][N],n,m;
char opt[N][4],pos[N],co[N];
int	main(int args, char** argv){
	Finn = fopen(argv[1], "r");int T;
	fscanf(Finn,"%d",&T);
	while(T--){
		fscanf(Finn,"%d%d",&n,&m);
		rep(i,1,n)rep(j,1,n)fscanf(Finn,"%d",&a[i][j]);
		rep(i,1,n)rep(j,1,n)fscanf(Finn,"%d",&b[i][j]);
		rep(i,1,m){
			fscanf(Finn,"%s",opt[i]+1);
			fscanf(Finn,"%d%d",&pos[i],&co[i]);
		}
		rep(i,1,m){
			int x;scanf("%d",&x);
			if(x>m||x<1){
				printf("Wrong\n");return 0;
			}
			if(opt[x][1]=='H')rep(j,1,n)a[pos[x]][j]=co[x];
			else rep(j,1,n)a[j][pos[x]]=co[x];
		}
		rep(i,1,n)rep(j,1,n){
			if(b[i][j]!=a[i][j]){printf("Wrong\n");return 0;}
		}
		printf("AC");if(T!=0)printf("\n");
	}
	return 0;
}








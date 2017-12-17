#include <stdio.h>
#include <string.h>

#define MAXN 105

int r,c,n,T;

int explode_time[MAXN];
int drop_size[MAXN];

int drop_id[MAXN][MAXN];

struct Pos {
	int x,y;
};

inline bool in_grid(const Pos &a)
{
	return a.x>=1 && a.x<=r && a.y>=1 && a.y<=c;
}

Pos U[MAXN],D[MAXN],L[MAXN],R[MAXN];
bool fU[MAXN],fD[MAXN],fL[MAXN],fR[MAXN];

Pos drop_pos[MAXN];

inline void move(Pos &p,bool &f,int dx,int dy)
{
	if (f) return;
	p.x+=dx;p.y+=dy;
	if (!in_grid(p)) {
		f=1;
		return;
	}
	int id=drop_id[p.x][p.y];
	if (id) {
		if (drop_size[id]<=4) ++drop_size[id];
		f=1;
	}
}

inline void solve()
{
	memset(explode_time,0,sizeof(explode_time));
	memset(drop_size,0,sizeof(drop_size));
	memset(drop_id,0,sizeof(drop_id));
	
	int i,j;
	
	for (i=1;i<=n;i++) {
		int x,y,size;
		scanf("%d%d%d",&x,&y,&size);
		drop_size[i]=size;
		drop_id[x][y]=i;
		drop_pos[i]=(Pos){x,y};
	}
	
	int x0,y0;
	scanf("%d%d",&x0,&y0);
	
	int cnt=1;
	fU[0]=fD[0]=fL[0]=fR[0]=0;
	U[0]=D[0]=L[0]=R[0]=(Pos){x0,y0};
	
	for (i=1;i<=T;i++) {
		for (j=0;j<cnt;j++) {
			move(U[j],fU[j],-1,0);
			move(D[j],fD[j],1,0);
			move(L[j],fL[j],0,-1);
			move(R[j],fR[j],0,1);
		}
		
		for (j=1;j<=n;j++) {
			if (drop_size[j]==5) {
				explode_time[j]=i;
				drop_id[drop_pos[j].x][drop_pos[j].y]=0;
				fU[cnt]=fD[cnt]=fL[cnt]=fR[cnt]=0;
				U[cnt]=D[cnt]=L[cnt]=R[cnt]=drop_pos[j];
				++cnt;
				drop_size[j]=0;
			}
		}
	}
	
	for (i=1;i<=n;i++) {
		if (explode_time[i]) {
			printf("0 %d\n",explode_time[i]);
		} else {
			printf("1 %d\n",drop_size[i]);
		}
	}
}

int main()
{
	while (scanf("%d%d%d%d",&r,&c,&n,&T)==4) {
		solve();
	}
}
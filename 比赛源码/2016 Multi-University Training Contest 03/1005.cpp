//============================================================================
// Author       : sunyaofeng
//============================================================================

//#pragma 	comment(linker, "/STACK:100240000,100240000")
#include	<stdio.h>
#include	<cstdlib>
#include	<cstring>
#include	<algorithm>

//#include	<bits/stdc++.h>

using	namespace	std;

#define DB		double
#define	lf		else if
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

#define	min(a,b)	((a)<(b)?(a):(b))
#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	100005
#define m	5000005
#define unt	unsigned int

int		N, Q, C, L[n], R[n], S[n], st[n], Dep[n];
int		D, Rt[n], ls[m], rs[m], Max[m], Min[m], Laz[m];
unt		Ans, Sum[m];

struct	Lin{
		int v, next;
}E[n << 1];

struct	Opt{
		int l, r;
}G[n];

void	Link(int u, int v){
		E[++C]= (Lin){v, st[u]};	st[u]= C;
		E[++C]= (Lin){u, st[v]};	st[v]= C;
}

void	DFS(int u,int f){
		Dep[u]= Dep[f] + 1;
		S[L[u]= ++C]= u;
		
		for (int i= st[u], v; i ; i= E[i].next)
			if	((v= E[i].v) ^ f)	DFS(v, u);
		
		R[u]= C;
}

void	Up(int u, int siz)	{
		Max[u]= max(Max[ls[u]], Max[rs[u]]) + Laz[u];
		Min[u]= min(Min[ls[u]], Min[rs[u]]) + Laz[u];
		Sum[u]= Sum[ls[u]] + Sum[rs[u]] + (unt)Laz[u] * siz;
}

void	Upd(int u, int siz, int v){
		Max[u]+= v;
		Min[u]+= v;
		Laz[u]+= v;
		Sum[u]+= siz*v;
}

void	Build(int&u, int l, int r){
		u= ++D;
		Laz[u]= 0;
		int Mid= (l+r) >> 1;
		
		if	(l == r)	{
			Max[u]= Min[u]= Sum[u]= Dep[S[l]];
			return;
		}
		
		Build(ls[u], l, Mid);
		Build(rs[u], Mid+1, r);
		Up(u, r-l+1);
}

void	Modify(int&u, int l, int r, int x, int y, int t){
		int v= u, Mid= (l+r) >> 1;
		u= ++D;
		
		ls[u]= ls[v];
		rs[u]= rs[v];
		
		Max[u]= Max[v];
		Min[u]= Min[v];
		Sum[u]= Sum[v];
		Laz[u]= Laz[v];
		
		if	(x <= l && r <= y)	{
			Upd(u, r-l+1, t);
			return;
		}
		
		if	(x <= Mid)	Modify(ls[u], l, Mid, x, y, t);
		if	(y > Mid)	Modify(rs[u], Mid+1, r, x, y, t);
		
		Up(u, r-l+1);
}

void	Query1(int u, int l, int r, int x, int y){
		if	(x <= l && r <= y)	{
			Ans+= Sum[u];
			return;
		}
		int Mid= (l+r) >> 1;
		
		Ans+= (unt)(y-x+1)*Laz[u];
		
		if	(y <= Mid)	Query1(ls[u], l, Mid, x, y);
		lf	(x > Mid)	Query1(rs[u], Mid+1, r, x, y);
		else	{
			Query1(ls[u], l, Mid, x, Mid);
			Query1(rs[u], Mid+1, r, Mid+1, y);
		}
}

void	Query2(int u, int l, int r, int x, int y, int lazy){
		if	(lazy+Min[u] >= Ans)return;
		if	(x <= l && r <= y)	{
			Ans= min(Ans, lazy+Min[u]);
			return;
		}
		int Mid= (l+r) >> 1;
		
		if	(x <= Mid)	Query2(ls[u], l, Mid, x, y, lazy+Laz[u]);
		if	(y > Mid)	Query2(rs[u], Mid+1, r, x, y, lazy+Laz[u]);
}

void	Query3(int u, int l, int r, int x, int y, int lazy= 0){
		if	(lazy + Max[u] <= Ans)	return;
		if	(x <= l && r <= y)	{
			Ans= max(Ans, lazy+Max[u]);
			return;
		}
		int Mid= (l+r) >> 1;
		
		if	(x <= Mid)	Query3(ls[u], l, Mid, x, y, lazy + Laz[u]);
		if	(y > Mid)	Query3(rs[u], Mid+1, r, x, y, lazy + Laz[u]);
}

void	Work(int u, int f){
		for (int i=st[u], v ; i ; i= E[i].next)
		if	((v= E[i].v) ^ f)	{
			Rt[v]= Rt[u];
			
			Modify(Rt[v], 1, N, 1, N, 1);
			Modify(Rt[v], 1, N, L[v], R[v], -2);
			Work(v, u);
		}
}

bool	Cmp(const Opt&a, const Opt&b)	{
		return	a.l < b.l;
}

int		main(){
		for	(;scanf("%d%d", &N, &Q) != EOF;C= D= 0){
			For(i, 1, N)	st[i]= 0;
			For(i, 2, N)	Link(IN(), IN());
		
			Dep[0]= -1;
			DFS(1, C= 0);
			Build(Rt[1]= 0, 1, N);
			Work(1, 0);
			
			Ans= 0;
			int	Cnt= 0;
			for (; Q-- ;){
				int K= IN(), P= IN(), T= IN();
				P= (Ans + P)%N + 1;
				Cnt+= K;
				
				For(i, 1, K)	{
					int x= IN();
					G[i]= (Opt){L[x], R[x]};
				}
				sort(G+1, G+K+1, Cmp);

				int x= 0;
				For(i, 1, K)	{
					if	(x && G[i].l <= G[x].r+1)	G[x].r= max(G[x].r, G[i].r);
						else	G[++x]= G[i];
				}
				K= x;

				if	(K == 1 && G[1].l==1 && G[1].r==N)	{
					puts("-1");	Ans=0;	continue;
				}

				if	(T == 1)	{
					Ans= 0;
					if	(K && G[1].l > 1)	Query1(Rt[P], 1, N, 1, G[1].l-1);
					For(i, 2, K)	Query1(Rt[P], 1, N, G[i-1].r+1, G[i].l-1);
					if	(K && G[K].r < N)	Query1(Rt[P], 1, N, G[K].r+1, N);
					if	(!K)	Query1(Rt[P], 1, N, 1, N);
					printf("%u\n", Ans);
				}
				lf	(T == 2)	{
					Ans= N;
					if	(K && G[1].l > 1)	Query2(Rt[P], 1, N, 1, G[1].l-1, 0);
					For(i, 2, K)	Query2(Rt[P], 1, N, G[i-1].r+1, G[i].l-1, 0);
					if	(K && G[K].r < N)	Query2(Rt[P], 1, N, G[K].r+1, N, 0);
					if	(!K)	Query2(Rt[P], 1, N, 1, N, 0);
					printf("%u\n", Ans);
				}	else	{
					Ans= 0;
					if	(K && G[1].l > 1)	Query3(Rt[P], 1, N, 1, G[1].l-1);
					For(i, 2, K)	Query3(Rt[P], 1, N, G[i-1].r+1, G[i].l-1);
					if	(K && G[K].r < N)	Query3(Rt[P], 1, N, G[K].r+1, N);
					if	(!K)	Query3(Rt[P], 1, N, 1, N);
					printf("%u\n", Ans);
				}
			}
		}
		
		return	0;
}

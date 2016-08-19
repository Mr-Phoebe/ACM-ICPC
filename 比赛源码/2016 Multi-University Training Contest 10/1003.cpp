#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 1010;
const LL INF = 1ll<<40;

struct Problem{
	LL c,d;
	bool friend operator < (const Problem &a,const Problem &b){
		return a.c<b.c;
	}
	void assign(LL a,LL b){
		c=a,d=b;
	}
};

struct Collection{
	LL deadline;
	int n;
	Problem pro[N];
	bool use[N];
	void init(){
		for(int i=1;i<=n;i++)
			use[i]=false;
	}
	int find(LL val){
		int pos=-1;
		for(int i=1;i<=n;i++){
			if(use[i]==false&&pro[i].c<=val&&(pos==-1||pro[pos].d<pro[i].d))
				pos=i;
		}
		return pos;
	}
	LL get(int pos){
		return pro[pos].d;
	}
	void modify(int pos){
		use[pos]=true;
	}
}a,b;

bool cal(Collection &a,Collection &b,LL w,LL z,LL deadline)
{
	a.init();b.init();
	int an=a.n,bn=b.n;
	LL cn=deadline-an-bn;
	LL t=0;

	while(an!=0||bn!=0){
		if(t>=deadline) return false;
		if(t>=a.deadline &&an!=0) return false;

		int id=a.find(w);
		if(id==-1){
			id=b.find(w);
			if(id==-1&&cn==0) return false;
			if(id==-1||(b.pro[id].d<z&&cn!=0)){
				LL step=1;
				while(1){
					if(step==cn) break;
					LL next=min(step*2,cn);
					int ia=a.find(w+next*z);
					int ib=b.find(w+next*z);
					if(ia!=-1) break;
					if(ib!=-1&&b.pro[ib].d>=z) break;
					step=next;
				}
				cn-=step;
				t+=step;
				w+=step*z;
			}
			else{
				w+=b.get(id);
				b.modify(id);
				bn--;
				t++;
			}
		}
		else{
			w+=a.get(id);
			a.modify(id);
			an--;
			t++;
		}
	}
	return true;
}

LL solve(Collection &a, Collection &b,LL w,LL z)
{
	int an=a.n,bn=b.n;
	if(an+bn==0) return 0;
	LL ans=-1,low=a.n+b.n,high=b.deadline;
	while(low<=high){
		LL m=(low+high)/2;
		if(cal(a,b,w,z,m)){
			ans=m;
			high=m-1;
		}
		else
			low=m+1;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int cs=1;cs<=t;cs++){
		int n;
		LL w,z;
		scanf("%d",&n);
		scanf("%lld %lld",&a.deadline,&b.deadline);
		scanf("%lld %lld",&w,&z);
		a.n=b.n=0;
		for(int i=1;i<=n;i++){
			LL c,d;
			char s[2];
			scanf("%lld %lld %s",&c,&d,s);
			if(s[0]=='A')
				a.pro[++a.n].assign(c,d);
			else
				b.pro[++b.n].assign(c,d);
		}
		LL ans;
		if(a.deadline<=b.deadline)
			ans=solve(a,b,w,z);
		else 
			ans=solve(b,a,w,z);
		if(ans==-1)
			printf("Poor Captain Chen\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}

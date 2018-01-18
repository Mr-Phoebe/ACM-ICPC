#include <stdio.h>
#include <algorithm>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

const int N=int(2e5)+5;

const ll inf=ll(1e18);

int n,m,k;

struct number{
	int sign;
	ll val;
	void read(){
		char c=0;
		while(c==0){
			switch(c=getchar()){
				case '+': sign=+1; break;
				case '-': sign=-1; break;
				case '0': sign=0; break;
				default: c=0; break;
			}
		}
		if(sign!=0){
			int val_;
			scanf("%d",&val_);
			val=val_;
		}
	}
	void print(){
		putchar(sign==+1?'+':sign==-1?'-':'0');
		if(sign!=0)
			printf(" %I64d",val);
	}
	friend bool operator < (const number &a,const number &b){
		if(a.sign!=b.sign) return a.sign<b.sign;
		if(a.sign==0) return false;
		if(a.sign==+1) return a.val<b.val; else return a.val>b.val;
	}
};

struct state{
	int cnt,loc,lim;
	ll val;
	bool moveable(int d) const{
		if(cnt<0) return false;
		if(d==0){
			return loc+1<lim;
		}
		else{
			return cnt-1>=0&&cnt<loc;
		}
	}
	state move(number *a,int d) const{
		if(d==0){
			return (state){cnt,loc+1,lim,val-a[loc].val+a[loc+1].val};
		}
		else{
			return (state){cnt-1,cnt,loc,val-a[cnt-1].val+a[cnt].val};
		}
	}
};

struct State{
	state sta,stb;
	bool flag;
	ll val() const{
		return sta.val+stb.val;
	}
	friend bool operator < (const State &a,const State &b){
		return a.val()<b.val();
	}
};

int na,nb;
number a[N],*b;
ll prea[N],preb[N];

priority_queue<State> q;

bool Main(){
	scanf("%d%d%d",&n,&m,&k);
	if(n==0) return false;
	for(int i=0;i<n;i++) a[i].read();
	sort(a,a+n);
	b=lower_bound(a,a+n,(number){0,0});
	na=b-a;
	nb=n-na;
	for(int i=0;i<nb;i++) if(b[i].sign==0) b[i]=(number){+1,-inf};
	reverse(b,b+nb);
	prea[0]=0;
	for(int i=0;i<na;i++) prea[i+1]=prea[i]+a[i].val;
	preb[0]=0;
	for(int i=0;i<nb;i++) preb[i+1]=preb[i]+b[i].val;
	while(!q.empty()) q.pop();
	for(int i=0;i<=m;i+=2) if(i<=na&&m-i<=nb){
		q.push((State){(state){i-1,i-1,na,prea[i]},(state){m-i-1,m-i-1,nb,preb[m-i]},false});
	}
	while(!q.empty()){
		State now=q.top(); q.pop();
		if(--k==0){
			(number){now.val()<-inf/2?0:+1,+now.val()}.print();
			printf("\n");
			return true;
		}
		if(!now.flag){
			for(int x=0;x<=1;x++) if(now.sta.moveable(x))
				q.push((State){now.sta.move(a,x),now.stb,false});
		}
		for(int y=0;y<=1;y++) if(now.stb.moveable(y))
			q.push((State){now.sta,now.stb.move(b,y),true});
	}
	reverse(a,a+na);
	reverse(b,b+nb);
	for(int i=0;i<n;i++) a[i].val*=-1;
	prea[0]=0;
	for(int i=0;i<na;i++) prea[i+1]=prea[i]+a[i].val;
	preb[0]=0;
	for(int i=0;i<nb;i++) preb[i+1]=preb[i]+b[i].val;
	for(int i=1;i<=m;i+=2) if(i<=na&&m-i<=nb){
		q.push((State){(state){i-1,i-1,na,prea[i]},(state){m-i-1,m-i-1,nb,preb[m-i]},false});
	}
	while(!q.empty()){
		State now=q.top(); q.pop();
		if(--k==0){
			(number){now.val()>+inf/2?0:-1,-now.val()}.print();
			printf("\n");
			return true;
		}
		if(!now.flag){
			for(int x=0;x<=1;x++) if(now.sta.moveable(x))
				q.push((State){now.sta.move(a,x),now.stb,false});
		}
		for(int y=0;y<=1;y++) if(now.stb.moveable(y))
			q.push((State){now.sta,now.stb.move(b,y),true});
	}
	return true;
}

int main(){
	while(Main());
//	eprintf("time=%ld\n",clock());
}

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
#define N 105
#define UI unsigned int
const char t[]=" 4294967296";

UI n;
int l;
char s[N];

int main(){
	while(scanf("%s",s+1)^-1){
		l=strlen(s+1);
		if(l>10){puts("TAT");continue;}
		if(l==10){
			bool flag=0;
			rep(i,1,10){
				if(t[i]<s[i]) break;
				if(t[i]>s[i]){flag=1;break;}
			}
			if(!flag){puts("TAT");continue;}
		}
		n=0;
		rep(i,1,l) n=n*10+s[i]-'0';
		if(!n){puts("TAT");continue;}
		int cnt=0;
		while(n^1){
			n=(UI)sqrt((double)n+0.5);
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}


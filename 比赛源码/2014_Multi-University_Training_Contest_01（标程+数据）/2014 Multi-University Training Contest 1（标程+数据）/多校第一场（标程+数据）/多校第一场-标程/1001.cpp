#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,p,q,i,j,k,l,r;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(scanf("%d%d",&n,&p)!=EOF){
		if (  ((n/(p-1))&1) )
			printf("YES\n");
		else
			printf("NO\n");
	}
}
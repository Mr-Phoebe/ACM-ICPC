#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[] = {-1,1,1,-1,1,-1,0,0,1,-1,-1,1,0,0,-1,1,-1,1,1,-1,0,0,0,0};
int T;
int main(){
	scanf("%d",&T);
	for(int re=1;re<=T;++re){
		int ans = 0;
		char ch[3];
		for(int i=0;i<24;++i){
			scanf("%s",ch);
			if(ch[0] == 'w' || ch[0] == 'y')
				ans += a[i];
		}
		printf("Case #%d: %s\n",re,ans%3?"NO":"YES");
	}
	return 0;
}

// r o b g w y

/*
	g g
	g g
o o w w r r
o o w w r r
	b b
	b b
	y y
	y y

*/

/*
	- +
	+ -
+ - 0 0 + -
- + 0 0 - +
	- +
	+ -
	0 0
	0 0

*/


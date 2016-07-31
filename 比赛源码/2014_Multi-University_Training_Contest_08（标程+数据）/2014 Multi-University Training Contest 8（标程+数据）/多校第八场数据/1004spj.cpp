#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cctype>
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
int n;
char s[1010],str[101000];
bitset<105> in_[105],ou_[105];
bitset<505> in[505],ou[505];
int g[505][505],p[505],vis[505];


int main(int argc, char** argv) {
	FILE *f = fopen(argv[1] , "r");
	while (1) {
		fscanf(f,"%d",&n);
		if (n==0) break;
		rep(i,0,n) {
			fscanf(f,"%s",s);
			rep(j,0,n) g[i][j]=s[j]-'0';
		}
		gets(str);
		stringstream os;
		os<<str;
		rep(i,0,n) os>>p[i];
		rep(i,0,n) {
			--p[i];
			if (p[i]>=n||p[i]<0) {
				printf("wa\n");
				return 0;
			}
			vis[i]=0;
		}
		if (n<=100) {
			rep(i,0,n) rep(j,0,n) ou_[i][j]=g[i][j];
			rep(i,0,n) rep(j,0,n) in_[j][i]=g[i][j];
			per(i,0,n) {
				if (vis[p[i]]) {
					printf("wa\n");
					return 0;
				}
				vis[p[i]]=1;
				rep(j,0,i) if (!g[p[j]][p[i]]) {
					if (!(ou_[p[j]]&in_[p[i]]).any()) {
						printf("wa\n");
						return 0;
					}
				}
			}
		} else {
			rep(i,0,n) rep(j,0,n) ou[i][j]=g[i][j];
			rep(i,0,n) rep(j,0,n) in[j][i]=g[i][j];
			per(i,0,n) {
				if (vis[p[i]]) {
					printf("wa\n");
					return 0;
				}
				vis[p[i]]=1;
				rep(j,0,i) if (!g[p[j]][p[i]]) {
					if (!(ou[p[j]]&in[p[i]]).any()) {
						printf("wa\n");
						return 0;
					}
				}
			}
		}
	}
	printf("AC!\n");
	return 0;
}

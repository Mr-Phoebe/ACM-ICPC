#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#define  MAXN 30
#define  INF 0x7FFFFFFF
#define  ll long long
using namespace std;
int a[MAXN][MAXN];
int main(void){
	int T;
	cin >> T;
	while(T--){
		int n, p;
		cin >> n >> p;
		int flag = 0;
		for(int i=1; i<=n; ++i){
			int sum = i*i-2*i-2*p;
			if(sum > 0){
				flag = i;
			}
		}
		int count = 0;
		int t = 0;
		for(int i=1; i<=flag; ++i){
			for(int j=i+1; j<=n; ++j){
				cout << i << " " << j << endl;
				count++;
				if(count == 2*n+p){
					t = 1;
					break;
				}
			}
			if(t == 1)
			 break;
		}
	} 

	return 0;
}
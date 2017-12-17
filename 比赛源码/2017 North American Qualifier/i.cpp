#include <stdio.h>
#include <cmath>
#include <cstring>

using namespace std;

int a[2000];

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (int i=1; i<=n; i++) scanf("%d", &a[i]);
		int ans=-1;
		for (int i=2; i<=n-1;i++) {
			if (a[i] != a[i-1]+1) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
}

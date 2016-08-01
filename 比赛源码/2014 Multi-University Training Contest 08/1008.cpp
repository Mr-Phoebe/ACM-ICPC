#include <cstdio>
long long x,s;
int __;
int main() {
	while (1) {
		scanf("%I64d%I64d",&x,&s);
		if (x==0&&s==0) break;
		for (int i=1;i<s;i++) {
			if (x<i+1) break;
			x=x-x/(i+1);
		}
		printf("Case #%d: %I64d\n",++__,x*s);
	}
}

// by ¦Î
// program sky  :)

#include <cstdio>

using namespace std;

int main(){
// say hello
	for(int a,v1,v2;~scanf("%d%d%d",&a,&v1,&v2);)
		if(a)
			if(v1>v2)
				printf("%.10lf\n",1.*v1*a/(v1*v1-v2*v2));
			else puts("Infinity");
		else puts("0.0000000000");
// never say goodbye
}

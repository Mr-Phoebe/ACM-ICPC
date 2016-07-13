#include<stdio.h>
#include<math.h>
#define pi 3.14159265357979

int main()
{
	int n,a,v;
	double s,t;
	while(scanf("%d%d%d",&n,&a,&v)!=EOF)
	{
		s=a/(2*sin(pi/n));
		t=s/v/cos(pi/2-pi/n);
		printf("%.5lf\n",t);
	}
	return 0;
} 
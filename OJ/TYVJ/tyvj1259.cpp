#include<stdio.h>

int f[10];
int check(int x)
{
while(x>0)
{
	if(!(f[x%10]))
		return 0;
	else x=x/10;
}
return 1;
}

int main()
{
int ans=0,i,j,x,n;
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&x);
	f[x]=1;
}
for(i=100;i<=999;i++)
	for(j=10;j<=9999/i;j++)
		if((j%10*i<1000)&&(j/10*i<1000))
			if((check(i))&&(check(j))&&(check(j%10*i))&&(check(j/10*i))&&(check(i*j)))
				ans++;
printf("%d\n",ans);
return 0;
}


/*
输入数据 Input Data [复制数据]
8
9 1 7 3 5 4 6 8
输出数据 Output Data [复制数据]
652
*/
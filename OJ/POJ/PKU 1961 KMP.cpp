#include <cstring>
#include<cstdio>
using namespace std;
#define maxlen 1000002
int P[maxlen];
char str[maxlen];
int main()
{

	int n = 1,len;//测试数据组数计数器
	while(scanf("%d",&len)!=EOF && len!=0)
	{
		scanf("%s",str);
		P[1] = 0;//P[]下标从1开始
		int j = 0;
		for (int i=2;i<=len;i++)
		{
			//除非j==0,否则失配就要右滑
			while( j>0 && str[j]!=str[i-1] )
				j = P[j];
			//配成的话，j要移动，事实上不移动的话P[i]=j+1
			if ( str[j] == str[i-1] )
				j++;
			//为了使得代码简洁，将两种情况（j==0和匹配）的赋值合并，但是有些损失可读性
			P[i] = j;
		}
		//k-P[k]是字符串向右移动的位数，总长度除以之，如能除尽，
		//结果就是重复次数，否则重复次数为1
		printf("Test case #%d\n",n++);
		for (int k=2;k<=len;k++)
			if ( k%(k-P[k])==0 && k/(k-P[k])!=1)
					printf("%d %d\n",k,k/(k-P[k]));
		printf("\n");
	}
}
#include <cstring>
#include<cstdio>
using namespace std;
#define maxlen 1000002
int P[maxlen];
char str[maxlen];
int main()
{

	int n = 1,len;//������������������
	while(scanf("%d",&len)!=EOF && len!=0)
	{
		scanf("%s",str);
		P[1] = 0;//P[]�±��1��ʼ
		int j = 0;
		for (int i=2;i<=len;i++)
		{
			//����j==0,����ʧ���Ҫ�һ�
			while( j>0 && str[j]!=str[i-1] )
				j = P[j];
			//��ɵĻ���jҪ�ƶ�����ʵ�ϲ��ƶ��Ļ�P[i]=j+1
			if ( str[j] == str[i-1] )
				j++;
			//Ϊ��ʹ�ô����࣬�����������j==0��ƥ�䣩�ĸ�ֵ�ϲ���������Щ��ʧ�ɶ���
			P[i] = j;
		}
		//k-P[k]���ַ��������ƶ���λ�����ܳ��ȳ���֮�����ܳ�����
		//��������ظ������������ظ�����Ϊ1
		printf("Test case #%d\n",n++);
		for (int k=2;k<=len;k++)
			if ( k%(k-P[k])==0 && k/(k-P[k])!=1)
					printf("%d %d\n",k,k/(k-P[k]));
		printf("\n");
	}
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std ;
struct ma
{
    int b,p;
};
int cmp(const ma &a,const ma &b)
{
    return a.p < b.p;
}
int main()
{
    int t;
    int c[110];
    scanf("%d",&t);
    while(t--)
	{
        int n;
        double dp = 0;
        ma s[110][110];
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
		{
            scanf("%d",&c[i]);
            for(int j = 0; j < c[i]; j++)
                scanf("%d%d",&s[i][j].b,&s[i][j].p);
            sort(&s[i][0],c[i]+&s[i][0],cmp);//                         (1)
        }
        for(int i = 0; i < n; i++)
		{         //ö�������豸
            for(int j = 0; j < c[i]; j++)
			{
                int mb = s[i][j].b,k;       //���赱ǰ���豸�����Ž�    (2)
                int sp = s[i][j].p;
                for(k = 0; k < n; k++)
				{
                    if(k==i) continue;
                    int q = 0;
                     //(1)�����򲻶ԵĻ�������Ͳ����ҵ���ȷ������Ԫ��
                     //�����B/P��B��ͨ��������������������豸�������С����������
                     //P���ܻ��ѣ�(2)�ļ��������������s[k][q].b>=mb������������s[k][q].b>=mb�����
                     //ҪʹB/P���s[k][q].p�ͱ�����С��֪��Ϊ��ôҪ�����˰ɣ���
                    while(q<c[k]&&s[k][q].b<mb) q++;
                    if(q>=c[k]) break;
                    sp += s[k][q].p;
                }
                //�鹻n���豸ʱ�����鵱ǰ����Ƿ����ŵģ�����ǣ���ô��������ֵ
                //ö�ٹ������豸֮�����Ž��ȷ����
                if(k>=n&&(mb/double(sp)>dp)) dp = mb*1.0/sp*1.0; 
            }
        }
        printf("%0.3f\n",dp);
    }
    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char str[3333];
int fla[999];
int main(void)
{
    int k,maxx=-1;
    gets(str);
    scanf("%d",&k);
    int len=strlen(str);
    if(k>=len)
        printf("%d\n",(k+len)/2*2);
    else
    {
	    int n=len+k;
	    for(int i=0;i<len;i++)//��ʼλ�� 
	    {
	        for(int j=1;j<=len-i;j++)//���� 
	        {
	            int ans=0;
	            for(int kk=i;kk<i+j;kk++)//��ظ� 
	            {
	                if(kk+j>=len&&kk+j<n)//���� 
	                    ans++;
	                else if(str[kk]==str[kk+j])//û������������ͬ 
	                    ans++;
	            }
	            if(ans==j)
	            	maxx=max(ans,maxx);
	        }
	    }
	    printf("%d\n",maxx*2);
    }
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio> 

using namespace std;


int cal_less(int a,int b)
{
	return a<b;
}

int main()
{
	int n,bit=0,i=0,k,count,num[1111111],t=0;
	char c;
	int T;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t=0;bit=0;i=0;
		num[i]=0;
		while(scanf("%c",&c))
		{
			if(c>='A'&&c<='Z')
			{
				switch (c)
				{
				case 'A': case'B': case'C':
					c='2';
					break;
				case 'D': case'E': case'F':
					c='3';
					break;
				case 'G': case'H': case'I':
					c='4';
					break;
				case 'J': case'K': case'L':
					c='5';
					break;
				case 'M': case'N': case'O':
					c='6';
					break;
				case 'P': case'R': case'S':
					c='7';
					break;
				case 'T': case'U': case'V':
					c='8';
					break;
				case 'W': case'X': case'Y':
					c='9';
					break;
				default:
					break;
				}
			}
			if(c>='0'&&c<='9')
			{
				num[i]=((int)c-48)+num[i]*10;
				bit++;
				if(bit>6)
				{
					i++;
					num[i]=0;
					bit=0;
					if(i>=n)
						break;
				}
			}			
		}
		sort(num,num+n,cal_less);
		count=1;
		for(k=0;k<n-1;k++)
		{
			if(num[k+1]==num[k])
				count++;
			if(count>1&&k+1<n-1&&num[k+1]!=num[k]||k+1>=n-1&&count>1)
			{
				printf("%03d-%04d %d\n",num[k]/10000,num[k]%10000,count);
				t++;
				count=1;
			}
		}
		if(t==0)
			printf("No duplicates.\n");
		printf("\n");
	} 
	return 0;
}    
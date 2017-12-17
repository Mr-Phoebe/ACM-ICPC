#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

bool isprime(int n)
{
	int m=(int)(sqrt(n)+0.5);
	if(n==2)
		return true;
	else if(n==0 || n==1)
		return false;
	for(int i=2;i<m;i++)
		if(n%i==0)
			return false;
	return true; 
}


int main()
{
	char ch;
	int letter[24]={0};
	int i;
	memset(letter,0,24);
	ch=getchar();
	while(ch!=' '&&ch!='\n')
	{
		letter[(int)ch-97]++;
		ch=getchar();
	}
	qsort(letter,24,sizeof(int),cmp);
	for(i=0;!letter[i];i++){}
	if(isprime(letter[23]-letter[i]))
		{
		cout<<"Lucky Word"<<endl;
		cout<<letter[23]-letter[i]<<endl;
		}
	else
		{
			cout<<"No Answer"<<endl;
			cout<<"0"<<endl;
		}
	return 0;
} 
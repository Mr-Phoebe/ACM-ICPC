#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int N;
char *s[10000];

void qsort(int x,int y)
{
	int i=x,j=y;
	char *m,*p;
	m=s[(x+y)/2];
	do
	{
		while(strcmp(m,s[i])>0)
			i++;
		while(strcmp(m,s[j])<0)
			j--;
		if(i<=j)
		{
			p=s[i];
			s[i]=s[j];
			s[j]=p;
			i++;j--;
		}
	}
	while(i<=j);
	if(x<j)
		qsort(x,j);
	if(i<y)
		qsort(i,y);
}


int main()
{
	int i;
	char *p;

	scanf("%d",&N);
	for(i=0;i<N;i++) 
	{
		p=(char*)malloc(333);
		scanf("%s",p);
		s[i]=p;	 
	}

	qsort(0,N-1);
	for(i=0;i<N;i++)
		printf("%s\n",s[i]);
	return 0;
}

#include<iostream>
#include<cstring>

using namespace std;



void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
    c=(char *) malloc(l*sizeof(char));
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=0;up=0;
    while(i>=0||j>=0)
        {
            if(i<0) x='0'; else x=a[i];
            if(j<0) y='0'; else y=b[j];
            z=x-'0'+y-'0';
            if(up) z+=1;
            if(z>9) {up=1;z%=10;} else up=0;
            c[k++]=z+'0';
            i--;j--;
        }
    if(up) c[k++]='1';
    i=0;
    c[k]='\0';
    for(k-=1;k>=0;k--)
        back[i++]=c[k];
    back[i]='\0';
} 

int main()
{
	char a[1500],b[1500],back[1500];
	int i=0,z=0;
	char ch;
	memset(a,'\0',1500);
	memset(b,'\0',1500);	
	while((ch=getchar())!='\n' && i<1500)
	{
		if((ch>='0' && ch<='9'))
			a[i++]=ch;
		else if(ch=='+')
		{
			a[i]='\0';
			add(a,b,back);
			for(z=0;z<strlen(back);z++)
				b[z]=back[z];
			b[z]='\0';
			memset(back,0,sizeof(back));
			memset(a,0,sizeof(a));
			i=0;
		}
		
	}
	add(a,b,back);
	printf("%s\n",back);
	return 0;
}

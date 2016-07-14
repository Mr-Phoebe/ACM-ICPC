#include<stdio.h>
#include<string.h>
  
int main()  
{  
    int i,j;  
    int len, temp;  
    char buf[20];  
    char s[200];

    while (gets(buf)!=NULL)
	{  
        temp=0;  
        if (buf[0]=='_')  
            continue;  
        for (i=1;i<10;i++)
            if (buf[i]=='o')  
                temp=temp*2+1;  
            else if (buf[i]==' ')  
                temp*=2;  
        if(temp!=2)        
            putchar(temp);
    }  
  
    return 0;  
}  
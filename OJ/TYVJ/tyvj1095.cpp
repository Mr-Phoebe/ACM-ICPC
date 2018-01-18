#include<iostream>  
#include<cstring> 

using namespace std; 

int f[2010][2010];  

int min(int a,int b,int c)
{
	int min=a>b?b:a;
	return min>c?c:min;
}


int main()  
{  
    char s1[2010],s2[2010];  
    int k,t,i,j;  
    gets(s1);  
    gets(s2);  
    cin>>k;
    int l1=strlen(s1);  
    int l2=strlen(s2);  
    for(i=1;i<=l1;i++)  
		for(j=1;j<=l2;j++)  
			f[i][j]=1000000;   
    for(i=1;i<=l1;i++)  
		f[i][0]=i*k;  
    for(i=1;i<=l2;i++)  
		f[0][i]=i*k;  
    for(i=1;i<=l1;i++)  
      for(j=1;j<=l2;j++)  
      {  
		  t=s1[i-1]-s2[j-1];  
		  if(t<0)
			  t=-t;
		  f[i][j]=min(f[i-1][j]+k,f[i][j-1]+k,f[i-1][j-1]+t);
      }  
  
    cout<<f[l1][l2]<<endl;  
    return 0;  
}  
#include<iostream>
#include<string>
#include<cstring>

#define maxsize 555

using namespace std;


typedef struct hp   
{   
    int len;   
    int s[maxsize];   
}HP;   
   
HP a,b,c;

void input(HP &a,string str)   
{   
    int i;   
    while(str[0]=='0' && str.size()!=1)   
        str.erase(0,1);   
    a.len=(int)str.size();   
    for(i=1;i<=a.len;++i)   
        a.s[i]=str[a.len-i]-48;   
    for (i=a.len+1;i<=maxsize;++i)   
        a.s[i]=0;   
}
   
void print(const HP &y)   
{   
    int i;   
    for(i=y.len;i>=1;i--)   
        cout<<y.s[i];   
    cout<<endl;   
}   
      
void multiplyh(const HP &a,const HP &b,HP &c)   
{   
    int i,j,len;   
    for(i=1;i<=maxsize;i++)
		c.s[i]=0;   
    for(i=1;i<=a.len;i++)   
        for(j=1;j<=b.len;j++)   
        {   
            c.s[i+j-1]+=a.s[i]*b.s[j];   
            c.s[i+j]+=c.s[i+j-1]/10;   
            c.s[i+j-1]%=10;   
        }   
        len=a.len+b.len+1;   
        while(len>1&&c.s[len]==0)
			len--;   
        c.len=len;   
}   
   
void init()
{
	for(int i=0;i<maxsize;i++)
	{
		a.s[i]=0;b.s[i]=0;c.s[i]=0;
	}
}   

int main()
{
	string stra,strb;
	while(cin>>stra)
	{
		cin>>strb;
		input(a,stra);
		input(b,strb); 
		multiplyh(a,b,c);
		print(c);
		stra.clear();strb.clear();
		init();
	}
	return 0;
} 
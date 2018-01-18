#include<iostream>
#include<cstring>
#include<string>    
   
using namespace std;   
   
#define maxsize 111   
   
typedef struct hp   
{   
    int len;   
    int s[maxsize+1];   
}HP;   
   
   
void input(HP &a,string str)   
{   
    int i;
	memset(a.s,0,maxsize);
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

void plush(const HP &a,HP &b)   
{   
    int i,len;
	HP c;
    for(i=1;i<=maxsize;i++) c.s[i]=0;   
    if(a.len>b.len)
		len=a.len;   
    else
		len=b.len;   
    for(i=1;i<=len;i++)   
    {   
        c.s[i]+=a.s[i]+b.s[i];   
        if(c.s[i]>=10)   
        {   
            c.s[i]-=10;   
            c.s[i+1]++;   
        }   
    }   
    if(c.s[len+1]>0)
		len++;   
    c.len=len;
    memset(b.s,0,c.len); 
	for(i=1;i<=c.len;i++)
		b.s[i]=c.s[i];
	b.len=c.len;   
}   

int main()
{
	string str1,str2;
	HP a,b;
	input(b,"0");
	while(cin>>str1,str1.compare("0")!=0)
	{
		input(a,str1);
		plush(a,b);
	}
	print(b);
	return 0;
}
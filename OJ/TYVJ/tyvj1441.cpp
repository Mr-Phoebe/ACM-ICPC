#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
 
//子函数：找到一个数组中的字符索引
int findIndex(char a[],int size,char key)
{
    for(int i=0;i<size;i++)
    {
       if (key==a[i])
       {
           return i;
       }
    }
    return -1;
}
 
//接受中序和后序数组，求前序输出：递归
void preOrder(char mid[],char post[],int size)
{
    if (0==size)
    {
       return ;
    }
    if (1==size)
    {
       cout<<post[size-1];
       return ;
    }
    int index=findIndex(mid,size,post[size-1]);
    if (index<0)
    {
       cout<<"error input";
       exit(1);
    }
    cout<<post[size-1];
    preOrder(mid,post,index);
    char * c=new char[size-index-1];
    char * d=new char[size-index-1];
    int k=0,m=0;
    for (int i=index+1,j=index;i<size,j<size-1;i++,j++)
    {
       c[k++]=mid[i];
       d[m++]=post[j];
    }
    preOrder(c,d,size-index-1);
    delete [] c;
    delete [] d;
 
}
 
int main()
{
    char *a;
    char *b;
    string temp;
    int i;
    cin>>temp;
    a=(char*)malloc(temp.length()+10);
    b=(char*)malloc(temp.length()+10);
    for(i=0;i<temp.length();i++)
    	a[i]=temp.at(i);
   	a[i]='\0';temp.clear();
   	cin>>temp;
   	for(i=0;i<temp.length();i++)
   		b[i]=temp.at(i);
	b[i]='\0';
    preOrder(a,b,temp.size());
    cout<<endl;
    return 0;
}
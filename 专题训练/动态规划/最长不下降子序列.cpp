#include <iostream>
using namespace std;
int find(int *a,int len,int n)//�޸ĺ�Ķ��ֲ��ң�������ֵΪx����a[x]>=n
{
    int left=0,right=len,mid=(left+right)/2;
    while(left<=right)
    {
       if(n>a[mid]) left=mid+1;
       else if(n<a[mid]) right=mid-1;
       else return mid;
       mid=(left+right)/2;
    }
    return left;
}
     
int main(void)
{
    int n,a[10010],c[10010],i,j,len;//�¿�һ����len,��������ÿ��ѭ��������c���Ѿ����ֵ��Ԫ�ص�����±�
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        c[0]=-1;
        c[1]=a[0];
        len=1;//��ʱֻ��c[1]�����������������еĳ���Ϊ1.
        for(i=1;i<n;i++)
        {
            j=find(c,len,a[i]);
            c[j]=a[i];
            if(j>len)//Ҫ����len,���ⲹ��һ�㣺�ɶ��ֲ��ҿ�֪jֻ���ܱ�len��1
                len=j;//����len
        }
        cout<<len<<endl;
    }
    return 0;
}
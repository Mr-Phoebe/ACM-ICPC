#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int k,t,i,j,l,temp;
    char a[105];
    int max,id;
    cin>>a>>k;
    l=strlen(a);
    for(i=0;i<l;i++)//�Ӹ�λ��ʼ�����������
    {
        if(i==l-1)//�����һλ�˳�
            break;
        max=a[i];id=i;
        t=k;
        if(k>l-1-i)
            t=l-1-i;
        for(j=i+1;j<=i+t;j++)
        {
            if(a[j]>max)
            {
                max=a[j];
                id=j;
            }
        }
        for(j=id;j>i;j--)
        	swap(a[j],a[j-1]);
        k-=(id-i);
    }
    cout<<a<<endl;
    return 0;
}

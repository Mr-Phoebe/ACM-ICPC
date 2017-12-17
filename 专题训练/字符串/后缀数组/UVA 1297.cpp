//============================================================================
// Name        : URAL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=2010;

/*
*suffix array
*�����㷨  O(n*logn)
*���������鳤��Ϊn,����0~n-1�У�������油һ��0
*build_sa( ,n+1, );//ע����n+1;
*getHeight(,n);
*���磺
*n   = 8;
*num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };ע��num���һλΪ0����������0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]Ϊ��Чֵ��rank[n]�ض�Ϊ0��Чֵ
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]Ϊ��Чֵ��sa[0]�ض�Ϊn����Чֵ
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]Ϊ��Чֵ
*
*/

int sa[MAXN];//SA���飬��ʾ��S��n����׺��С�����������ź����
             //�ĺ�׺�Ŀ�ͷλ��˳�η���SA��
int t1[MAXN],t2[MAXN],c[MAXN];//��SA������Ҫ���м����������Ҫ��ֵ
int rank[MAXN],height[MAXN];
//��������ַ�������s�����У���s[0]��s[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������
void build_sa(int s[],int n,int m)
{
    int i,j,p,*x=t1,*y=t2;
    //��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //ֱ������sa��������ڶ��ؼ���
        for(i=n-j;i<n;i++)y[p++]=i;//�����j�����ڶ��ؼ���Ϊ�յ���С
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        //��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
        //���������һ�ؼ���
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //����sa��x��������µ�x����
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;//�´λ�����������ֵ
    }
}
void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rank[i]]=k;
    }
}

int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1;i<=n;i++)best[0][i]=i;
    for(int i=1;i<=mm[n];i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            int a=best[i-1][j];
            int b=best[i-1][j+(1<<(i-1))];
            if(RMQ[a]<RMQ[b])best[i][j]=a;
            else best[i][j]=b;
        }
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}

int lcp(int a,int b)
{
    a=rank[a];b=rank[b];
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];
}
int r[MAXN];
char str[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",&str)==1)
    {
        int len=strlen(str);
        int n=2*len+1;
        for(int i=0;i<len;i++)r[i]=str[i];
        r[len]=1;//����������Ķ�Ӧ�ò�ͬ
        for(int i=0;i<len;i++)r[i+len+1]=str[len-1-i];
        r[n]=0;
        build_sa(r,n+1,128);
        getHeight(r,n);
        for(int i=1;i<=n;i++)RMQ[i]=height[i];
        initRMQ(n);
        int ans=0,st;
        int tmp;
        for(int i=0;i<len;i++)
        {
            tmp=lcp(i,n-i);//ż�Գ�
            if(2*tmp>ans)
            {
                ans=2*tmp;
                st=i-tmp;
            }
            tmp=lcp(i,n-i-1);//�����Գ�
            if(2*tmp-1>ans)
            {
                ans=2*tmp-1;
                st=i-tmp+1;
            }
        }
        str[st+ans]=0;
        printf("%s\n",str+st);
    }
    return 0;
}
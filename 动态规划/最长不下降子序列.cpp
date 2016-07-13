#include <iostream>
using namespace std;
int find(int *a,int len,int n)//修改后的二分查找，若返回值为x，则a[x]>=n
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
    int n,a[10010],c[10010],i,j,len;//新开一变量len,用来储存每次循环结束后c中已经求出值的元素的最大下标
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        c[0]=-1;
        c[1]=a[0];
        len=1;//此时只有c[1]求出来，最长递增子序列的长度为1.
        for(i=1;i<n;i++)
        {
            j=find(c,len,a[i]);
            c[j]=a[i];
            if(j>len)//要更新len,另外补充一点：由二分查找可知j只可能比len大1
                len=j;//更新len
        }
        cout<<len<<endl;
    }
    return 0;
}
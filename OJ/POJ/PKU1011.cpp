#include <iostream>
#include <algorithm>
using namespace std;
int sticks[65];
int used[65];
int n,len;
bool dfs(int i,int l,int t)//i为当前试取的棍子序号,l为要拼成一根完整的棍子还需要的长度,t初值为所有棍子总长度 
{
    if(l==0)
    {
        t-=len;
        
        if(t==0)return true;
        
        for(i=0;used[i];++i);            //剪枝1：搜索下一根大棍子的时候，找到第一个还没有使用的小棍子开始
        
        used[i]=1;                           //由于排序过，找到的第一根肯定最长，也肯定要使用，所以从下一根开始搜索
        if(dfs(i+1,len-sticks[i],t))return true;
        used[i]=0;
            
        t+=len;
    }
    else
    {
        for(int j=i;j<n;++j)
        {
            if(j>0&&(sticks[j]==sticks[j-1]&&!used[j-1]))  //剪枝2：前后两根长度相等时，如果前面那根没被使用，也就是由前面那根
                continue;                                                //开始搜索不到正确结果，那么再从这根开始也肯定搜索不出正确结果，此剪枝威力较大
                                                                                  
            if(!used[j]&&l>=sticks[j])   //剪枝3：最简单的剪枝，要拼成一根大棍子还需要的长度L>=当前小棍子长度，才能选用                           
            {
                l-=sticks[j];
                used[j]=1;
                if(dfs(j,l,t))
					return true;
                l+=sticks[j];
                used[j]=0;               
                if(sticks[j]==l)    //剪枝4：威力巨大的剪枝，程序要运行到此处说明往下的搜索失败，若本次的小棍长度刚好填满剩下长度，但是后
                    break;           //面的搜索失败，则应该返回上一层
            }
        }
    }
    return false;
}
bool cmp(const int a, const int b)
{ 
    return a>b; 
}
int main()
{
    while(cin>>n&&n)
    {
        int sum=0;
        for(int i=0;i<n;++i)
        {
            cin>>sticks[i];
            sum+=sticks[i];
            used[i]=0;
        }
        
        sort(sticks,sticks+n,cmp);   //剪枝5：从大到小排序后可大大减少递归次数
        
        bool flag=false;
        for(len=sticks[0];len<=sum/2;++len)   //剪枝6：大棍长度一定是所有小棍长度之和的因数，且最小因数应该不小于小棍中最长的长度
        {
            if(sum%len==0)     
            {
                if(dfs(0,len,sum))
                {
                    flag=true;
                    cout<<len<<endl;
                    break;
                }
            }
        }
        if(!flag)
            cout<<sum<<endl;
    }
    return 0;
}
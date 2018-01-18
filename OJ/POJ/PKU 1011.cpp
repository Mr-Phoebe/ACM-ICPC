#include <iostream>
#include <algorithm>
using namespace std;
int sticks[65];
int used[65];
int n,len;
bool dfs(int i,int l,int t)//iΪ��ǰ��ȡ�Ĺ������,lΪҪƴ��һ�������Ĺ��ӻ���Ҫ�ĳ���,t��ֵΪ���й����ܳ��� 
{
    if(l==0)
    {
        t-=len;
        
        if(t==0)return true;
        
        for(i=0;used[i];++i);            //��֦1��������һ������ӵ�ʱ���ҵ���һ����û��ʹ�õ�С���ӿ�ʼ
        
        used[i]=1;                           //������������ҵ��ĵ�һ���϶����Ҳ�϶�Ҫʹ�ã����Դ���һ����ʼ����
        if(dfs(i+1,len-sticks[i],t))return true;
        used[i]=0;
            
        t+=len;
    }
    else
    {
        for(int j=i;j<n;++j)
        {
            if(j>0&&(sticks[j]==sticks[j-1]&&!used[j-1]))  //��֦2��ǰ�������������ʱ�����ǰ���Ǹ�û��ʹ�ã�Ҳ������ǰ���Ǹ�
                continue;                                                //��ʼ����������ȷ�������ô�ٴ������ʼҲ�϶�����������ȷ������˼�֦�����ϴ�
                                                                                  
            if(!used[j]&&l>=sticks[j])   //��֦3����򵥵ļ�֦��Ҫƴ��һ������ӻ���Ҫ�ĳ���L>=��ǰС���ӳ��ȣ�����ѡ��                           
            {
                l-=sticks[j];
                used[j]=1;
                if(dfs(j,l,t))
					return true;
                l+=sticks[j];
                used[j]=0;               
                if(sticks[j]==l)    //��֦4�������޴�ļ�֦������Ҫ���е��˴�˵�����µ�����ʧ�ܣ������ε�С�����ȸպ�����ʣ�³��ȣ����Ǻ�
                    break;           //�������ʧ�ܣ���Ӧ�÷�����һ��
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
        
        sort(sticks,sticks+n,cmp);   //��֦5���Ӵ�С�����ɴ����ٵݹ����
        
        bool flag=false;
        for(len=sticks[0];len<=sum/2;++len)   //��֦6���������һ��������С������֮�͵�����������С����Ӧ�ò�С��С������ĳ���
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
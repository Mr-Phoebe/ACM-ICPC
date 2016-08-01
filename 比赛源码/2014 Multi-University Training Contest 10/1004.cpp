#include<cstdio>
int main()
{
    int ti;
    scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        int n;scanf("%d",&n);
        int sum=0,max=0;
        for(int i=0;i<n;i++)
        {
            int tmp;scanf("%d",&tmp);
            sum+=tmp;
            if(tmp>max)max=tmp;
        }
        if(max<(sum+1)/2)max=(sum+1)/2;
        printf("Case #%d: %d\n",ca,max);
    }
}

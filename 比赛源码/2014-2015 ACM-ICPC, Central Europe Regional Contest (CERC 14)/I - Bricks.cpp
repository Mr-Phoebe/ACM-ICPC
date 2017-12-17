#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

long long num[MAXN];
char type[MAXN];

int t,n;
int Index;
long long sumb,sumw;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        Index = 0;
        sumb = sumw = 0;

        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            long long tmpn;
            char tmpt[5];
            scanf("%I64d%s",&tmpn , tmpt);

            if(tmpt[0] == 'B') sumb += tmpn;
            else sumw += tmpn;

            if(Index != 0 && tmpt[0] == type[Index])
            {
                num[Index] += tmpn;
            }
            else
            {
                Index++;
                type[Index] = tmpt[0];
                num[Index] = tmpn;
            }
        }

        if(sumw == 0)
        {
            printf("%I64d\n",sumb);
            continue;
        }
        else if(sumb == 0)
        {
            printf("%I64d\n",sumw);
            continue;
        }

        long long numw = 0,numb = 0;

        int ans = 0;

        for(int i=1;i<=Index;i++)
        {
            if(type[i] == 'B')
            {
                if(numw == 0)
                {
                    numb += num[i];
                    continue;
                }

                if(numw * sumb % sumw != 0)
                {
                //cout<<'*'<<endl;
                    numb += num[i];
                    continue;
                }

                long long to = numw * sumb / sumw;
//cout<<to<<'@'<<endl;
                if(to > numb && to <= numb + num[i])
                {
                    ans++;
                    numb = numb + num[i] - to;
                    numw = 0;
                }
                else
                {
                    numb += num[i];
                }
            }
            else
            {
                if(numb == 0)
                {
                    numw += num[i];
                    continue;
                }

                if(numb * sumw % sumb != 0)
                {
                    numw += num[i];
                    continue;
                }

                long long to = numb * sumw / sumb;

                if(to > numw && to <= numw + num[i])
                {
                    ans++;
                    numw = numw + num[i] - to;
                    numb = 0;
                }
                else
                {
                    numw += num[i];
                }
                //cout<<numw<<' '<<numb<<endl;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
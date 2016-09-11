#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
//	freopen("data.txt","r",stdin);
    char s1[1100], s2[1100];
    int x=0, a[26], len1, len2, i, y=0;
    scanf("%s%s",s1,s2);
    memset(a,0,sizeof(a));
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0; i<len1; i++)
    {
        a[s1[i]-'a']++;
    }
    for(i=0; i<len2; i++)
    {
        if(a[s2[i]-'a']==0)
        {
            y=1;
            break;
        }
    }
    if(y)
        printf("-1\n");
    else
    {
        for(i=0; i<len2; i++)
        {
            if(a[s2[i]-'a']>0)
            {
                x++;
                a[s2[i]-'a']--;
            }
        }
        if(x)
            printf("%d\n",x);
        else
            printf("-1\n");
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string dp[22][22][44];

int m,n;

int main()
{
    freopen("merge.in","r",stdin);
    freopen("merge.out","w",stdout);
    scanf("%d%d",&m,&n);
    dp[1][1][1] = "x1&y1";
    dp[1][1][2] = "x1|y1";

    for(int i=2; i<=min(m,n); i++)
    {
        dp[i][i][1] = "x1&y1";
        for(int j=2; j<=i; j++)
            dp[i][i][j] = "(" + dp[j-1][j-1][j] + ")&(x" + char(j+'0') + "&y" + char(j+'0') + ")";

        for(int j=i+1; j<=2*i; j++)
        {
            dp[i][i][j] = dp[i][i][2*i+1-j];
            //cout<<i<<' '<<j<<' '<<dp[i][i][j]<<"###"<<endl;
            for(int p=0; p<dp[i][i][j].length(); p++)
            {
                if(dp[i][i][j][p] == '&') dp[i][i][j][p] = '|';
                else if(dp[i][i][j][p] == '|') dp[i][i][j][p] = '&';
                else if(dp[i][i][j][p] == 'x' || dp[i][i][j][p] == 'y') dp[i][i][j][p+1] = char(i+1-int(dp[i][i][j][p+1]-'0')+'0');
            }
            //cout<<dp[i][i][j]<<"%%%"<<endl;
        }
    }

    if(m > n)
    {
        for(int i=n+1; i<=m; i++)
        {
            dp[i][n][1] = "x1&y1";
            for(int j=2; j<=min((i+n+1)/2,n); j++)
                dp[i][n][j] = "(" + dp[j-1][j-1][j] + ")&(x" + char(j+'0') + "&y" + char(j+'0') + ")";

            for(int j=min((i+n+1)/2,n)+1; j<=(i+n+1)/2; j++)
                dp[i][n][j] = "(" + dp[j-1][n][j] + ")&x" + char(j+'0');

            for(int j=(i+n+1)/2+1; j<=i+n; j++)
            {
                dp[i][n][j] = dp[i][n][i+n+1-j];
                //cout<<i<<' '<<j<<' '<<dp[i][i][j]<<"###"<<endl;
                for(int p=0; p<dp[i][n][j].length(); p++)
                {
                    if(dp[i][n][j][p] == '&') dp[i][n][j][p] = '|';
                    else if(dp[i][n][j][p] == '|') dp[i][n][j][p] = '&';
                    else if(dp[i][n][j][p] == 'x') dp[i][n][j][p+1] = char(i+1-int(dp[i][n][j][p+1]-'0')+'0');
                    else if(dp[i][n][j][p] == 'y') dp[i][n][j][p+1] = char(n+1-int(dp[i][n][j][p+1]-'0')+'0');
                }
                //cout<<dp[i][i][j]<<"%%%"<<endl;
            }
        }
    }
    else if(m < n)
    {
        for(int i=m+1; i<=n; i++)
        {
            dp[m][i][1] = "x1&y1";
            for(int j=2; j<=min((i+m+1)/2,m); j++)
                dp[m][i][j] = "(" + dp[j-1][j-1][j] + ")&(x" + char(j+'0') + "&y" + char(j+'0') + ")";

            for(int j=min((i+m+1)/2,m)+1; j<=(i+m+1)/2; j++)
                dp[m][i][j] = "(" + dp[m][j-1][j] + ")&y" + char(j+'0');

            for(int j=(i+m+1)/2+1; j<=i+m; j++)
            {
                dp[m][i][j] = dp[m][i][i+m+1-j];
                //cout<<i<<' '<<j<<' '<<dp[i][i][j]<<"###"<<endl;
                for(int p=0; p<dp[m][i][j].length(); p++)
                {
                    if(dp[m][i][j][p] == '&') dp[m][i][j][p] = '|';
                    else if(dp[m][i][j][p] == '|') dp[m][i][j][p] = '&';
                    else if(dp[m][i][j][p] == 'y') dp[m][i][j][p+1] = char(i+1-int(dp[m][i][j][p+1]-'0')+'0');
                    else if(dp[m][i][j][p] == 'x') dp[m][i][j][p+1] = char(m+1-int(dp[m][i][j][p+1]-'0')+'0');
                }
                //cout<<dp[i][i][j]<<"%%%"<<endl;
            }
        }
    }

    for(int i=1; i<=m+n; i++)
    {
        for(int j=0; j<dp[m][n][i].length(); j++)
        {
            if(dp[m][n][i][j]>48 && dp[m][n][i][j]<=69)
                cout<<int(dp[m][n][i][j]-48);
            else
                cout<<dp[m][n][i][j];
        }
        cout<<endl;
    }
    return 0;
}

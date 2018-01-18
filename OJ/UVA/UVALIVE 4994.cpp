#include <bits/stdc++.h>

using namespace std;

string str[10];
int a[10];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case %d: ", i);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            a[i] = i;
            cin >> str[i];
        }
        int minn = 100;
        do
        {
            string now = str[a[0]];
            for(int i = 0; i < n; i++)
            {
                int len = min(now.size(), str[a[i]].size());
                for(int j = len; j >= 0; j--)
                    if(now.substr(now.size()-j, now.size()) == str[a[i]].substr(0, j))
                    {
                        now += str[a[i]].substr(j, str[a[i]].size());
                        break;
                    }
            }
            minn = min(minn, (int)now.size());
        }
        while(next_permutation(a, a+n));
        printf("%d\n", minn);
    }
    return 0;
}

#include <bits/stdc++.h>

char str[500010];
unsigned hash[500010];

unsigned getHash(int l, int r)   //[l, r)
{
    return hash[l] - (hash[r] << (r-l));
}

void MAIN()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    hash[n] = 0;
    for(int i = n-1; i >= 0; --i)
        hash[i] = str[i] - 'a' + (hash[i+1]<<1);
    for(int len = 1; true; ++len)
    {
        std::vector<unsigned> v(n-len+1);
        for(int l = 0; l + len <= n; ++l)
            v[l] = getHash(l, l+len);
        std::sort(v.begin(), v.end());
        //v.erase(std::unique(v.begin(), v.end()), v.end());
        std::unique(v.begin(), v.end());
        if(v.size() == 1u<<len)
            continue;
        unsigned retState = 0;
        while(v[retState] == retState)
            ++retState;
        printf("%d\n", len);
        for(int i = 0; i < len; ++i)
            printf("%c", ((retState >> i) & 1) == 0 ? 'a' : 'b');
        puts("");
        break;
    }
}

int main()
{
    MAIN();
    return 0;
}

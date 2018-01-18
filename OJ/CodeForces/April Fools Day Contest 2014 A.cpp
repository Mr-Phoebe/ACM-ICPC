#include <cstdio>

using namespace std;

const int maxn = 20 + 5;

int main()
{
    char s1[maxn], s2[maxn];
    while(scanf("%s%s", s1, s2) == 2)
	{
        int p1 = 0, p2 = 0;
        for(int i = 0; s1[i]; i += 2)
		{
            if(s1[i] == s2[i]) continue;
            if(s1[i] == '8') s2[i] == '[' ? p1++ : p2++;
            else if(s1[i] == '[') s2[i] == '(' ? p1++ : p2++;
            else s2[i] == '8' ? p1++ : p2++;
        }
        p1 > p2 ? puts("TEAM 1 WINS") : (p1 < p2 ? puts("TEAM 2 WINS") : puts("TIE"));
    }
    return 0;
}
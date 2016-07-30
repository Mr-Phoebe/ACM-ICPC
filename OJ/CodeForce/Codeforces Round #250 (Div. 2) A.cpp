#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
char a[maxn], b[maxn], c[maxn], d[maxn];

struct node
{
    int len;
    char letter;
}choice[5];

int cmp(node x, node y)
{
    return x.len < y.len;
}

int main()
{
    while (cin >> a >> b >> c >> d)
    {
        memset(choice, 0, sizeof(choice));
        choice[0].len = strlen(a) - 2;
        choice[0].letter = 'A';
        choice[1].len = strlen(b) - 2;
        choice[1].letter = 'B';
        choice[2].len = strlen(c) - 2;
        choice[2].letter = 'C';
        choice[3].len = strlen(d) - 2;
        choice[3].letter = 'D';
        sort(choice, choice+4, cmp);

        if (2*choice[0].len <= choice[1].len)
        {
            if (choice[3].len >= 2*choice[2].len)//所有不能选择的情况就选择C 
                printf("C\n");
            else
                printf("%c\n", choice[0].letter);
        }
        else if (choice[3].len >= 2*choice[2].len)
        {
            if (2*choice[0].len <= choice[1].len)
                printf("C\n");
            else
                printf("%c\n", choice[3].letter);
        }
        else
            printf("C\n");
    }
    return 0;
}
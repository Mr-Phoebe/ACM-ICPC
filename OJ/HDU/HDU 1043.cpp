#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

bool used[500000];
char op[500000];
int pre_state[500000];
int factorial[10];
int q1[500000], q2[500000], head, tail;
int ten[10];

inline void make_init()
{
    factorial[0] = ten[0] = 1;
    for(int i = 1; i <= 9; i++)
        factorial[i] = factorial[i-1] * i, ten[i] = ten[i-1] * 10;
}

inline int get_state(int _p)
{
    int ret = 0;
    bool marked[9] = { false };
    for(int i = 1; i < 10; i++)
    {
        int num = _p%10, cnt = 0;
        _p/=10;
        for(int j = num-1; j >= 0; j--)
            if(marked[j])
                cnt++;
        ret += cnt*factorial[i-1];
        marked[num] = true;
    }
    return ret;
}

void find_all_state()
{
    int init_state = get_state(123456780);
    head = tail = 0;
    q1[tail] = init_state;
    q2[tail++] = 123456780;
    memset(used, 0, sizeof used);
    used[init_state] = true;
    pre_state[init_state] = -1;
    while(head <= tail)
    {
        int now_state = q1[head], now_p = q2[head], pos = 1;
        head++;
        for(int tmp = now_p; tmp%10; tmp /= 10, pos++)
            ;
        int next_state, next_p;
        if(pos < 7)
        {
            next_p = now_p + (now_p % ten[pos+3]) / ten[pos+2] * (ten[pos-1] - ten[pos+2]);
            next_state = get_state(next_p);
            if(!used[next_state])
            {
                q1[tail] = next_state;
                q2[tail++] = next_p;
                pre_state[next_state] = now_state;
                used[next_state] = true;
                op[next_state] = 'd';
            }
        }
        if(pos > 3)
        {
            next_p = now_p + now_p % ten[pos-3] / ten[pos-4] * (ten[pos-1] - ten[pos-4]);
            next_state = get_state(next_p);
            if(!used[next_state])
            {
                q1[tail] = next_state;
                q2[tail++] = next_p;
                pre_state[next_state] = now_state;
                used[next_state] = true;
                op[next_state] = 'u';
            }
        }
        if(pos%3 != 1)
        {
            next_p = now_p + now_p % ten[pos-1] / ten[pos-2] * (ten[pos-1] - ten[pos-2]);
            next_state = get_state(next_p);
            if(!used[next_state])
            {
                q1[tail] = next_state;
                q2[tail++] = next_p;
                pre_state[next_state] = now_state;
                used[next_state] = true;
                op[next_state] = 'l';
            }
        }
        if(pos%3 != 0)
        {
            next_p = now_p + now_p % ten[pos+1] / ten[pos] * (ten[pos-1] - ten[pos]);
            next_state = get_state(next_p);
            if(!used[next_state])
            {
                q1[tail] = next_state;
                q2[tail++] = next_p;
                pre_state[next_state] = now_state;
                used[next_state] = true;
                op[next_state] = 'r';
            }
        }
    }
}

int main()
{
    char str[3];
    make_init();
    find_all_state();
    while(scanf("%s", str) > 0)
    {
        int _p = (str[0] == 'x' ? '0' : str[0]) - '0';
        for(int i = 1; i < 9; i++)
        {
            scanf("%s", str);
            if(str[0] == 'x')
                str[0] = '0';
            _p = _p*10 + str[0] - '0';
        }
        int state = get_state(_p);
        if(used[state])
        {
            for(; pre_state[state] != -1; state = pre_state[state])
                putchar(op[state]);
            puts("");
        }
        else
            puts("unsolvable");
    }
    return 0;
}

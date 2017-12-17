#include <bits/stdc++.h>

const double eps = 1e-5;

inline int sgn(double x)
{
    return x < -eps ? -1 : x > eps;
}

struct node
{
    int id, rk;
    double score;
    bool operator < (const node &rhs) const
    {
        return sgn(score - rhs.score) == 1;
    }
};


bool cmp(node const &lhs, node const &rhs)
{
    return lhs.id < rhs.id;
}

node team[110];
bool success[110][110][15], maintainWell[110];

void MAIN()
{
    int n, q, s, c;
    scanf("%d%d%d%d", &n, &q, &s, &c);
    for(int i = 1; i <= n; i++)
        team[i].id = i, team[i].rk = 1, team[i].score = s;
    while(c--)
    {
        int k;
        scanf("%d", &k);
        memset(success, 0, sizeof success);
        while(k--)
        {
            int attacker, defender, service;
            scanf("%d%d%d", &attacker, &defender, &service);
            success[attacker][defender][service] = true;
        }
        for(int service = 1; service <= q; ++service)
        {
            for(int defender = 1; defender <= n; ++defender)
            {
                int attackerCnt = 0;
                for(int attacker = 1; attacker <= n; ++attacker)
                {
                    if(success[attacker][defender][service])
                        ++attackerCnt;
                }
                if(attackerCnt == 0)
                    continue;
                double add = (n - 1) * 1.0 / attackerCnt;
                for(int i = 1; i <= n; i++)
                {
                    if(success[i][defender][service])
                        team[i].score += add;
                }
                team[defender].score -= n-1;
            }
        }
        for(int service = 1, tmp; service <= q; ++service)
        {
            int successCnt = 0;
            for(int id = 1; id <= n; id++)
            {
                scanf("%d", &tmp);
                maintainWell[id] = tmp;
                successCnt += tmp;
                team[id].score -= tmp == 0 ? n - 1 : 0;
            }
            if(successCnt == n || successCnt == 0)
                continue;
            double add = (n - 1) * 1.0 / successCnt;
            add *= (n - successCnt);
            for(int id = 1; id <= n; id++)
                if(maintainWell[id] == true)
                    team[id].score += add;
        }
        std::sort(team + 1, team + 1 + n);
        for(int id = 2; id <= n; id++)
        {
            if(sgn(team[id].score - team[id - 1].score) == 0)
                team[id].rk = team[id - 1].rk;
            else
                team[id].rk = id;
        }
        std::sort(team + 1, team + 1 + n, cmp);
        int u;
        scanf("%d", &u);
        for(int i = 0, id; i < u; i++)
        {
            scanf("%d", &id);
            printf("%f %d\n", team[id].score, team[id].rk);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
        MAIN();
    return 0;
}

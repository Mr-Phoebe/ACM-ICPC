#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXPT=500007;   //���ڵ���
const int size=4;     //�ӽڵ���

class Ac_Automat
{
private:
    struct Node
    {
        Node *fail;
        Node *next[size];
        bool flag;
        int id;
        void newnode () //���ɽڵ�
        {
            fail=NULL;
            for (int i=0; i<size; i++)
                next[i]=NULL;
            flag=false;
        }
    };

    Node *q[MAXPT],H[MAXPT],*root;
    int ID[128];
    int fr,tl,t;
public:

    int dp[1005][1005];
    void Init ()
    {
        fr = tl = 0;
        t = 0;
        H[t].newnode();
        H[t].id=t;  //��Trie���ϵ�ÿһ���ڵ��һ��״̬��
        root = &H[t++];
        ID['A']=0;
        ID['G']=1;
        ID['C']=2;
        ID['T']=3;
    }

    void Insert (const char *str)
    {
        Node *cur = root;
        for (const char *p=str; *p; p++)
        {
            int k=ID[*p];
            if (cur->next[k] == NULL)
            {
                H[t].newnode();
                H[t].id = t;//����״̬�ı��
                cur->next[k] = &H[t++];
            }
            cur = cur->next[k];
        }
        cur->flag=true;   //�ǵ��ʽ���
    }

    void Build()
    {
        root->fail = NULL;
        q[tl] = root;
        while (fr <= tl)
        {
            Node *tmp = q[fr++];

            //����������aact  aac���������ֻҪ����aac���ǷǷ��ĵ��в�����
            if (tmp != root)
                tmp->flag = tmp->flag||tmp->fail->flag;

            for (int i=0; i<size; i++)
            {
                //����Ҫ����ÿһ��nextΪ�յ�ָ��,����ѭ��ƥ��
                if (tmp->next[i] == NULL)
                {
                    if (tmp == root) tmp->next[i] = root;
                    else tmp->next[i] = tmp->fail->next[i];
                }
                else//����ƥ��ʧ��ָ��
                {
                    if (tmp == root)
                        tmp->next[i]->fail = root;
                    else
                    {
                        Node *p = tmp->fail;
                        while (p != NULL)
                        {
                            if (p->next[i])
                            {
                                tmp->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if (p == NULL)
                            tmp->next[i]->fail = root;
                    }
                    q[++tl] = tmp->next[i];
                }
            }
        }
    }

    int Deal(const char *str)
    {
        int len = strlen(str);

        for (int i=0; i<=len; i++)
            for (int j=0; j<t; j++)
                dp[i][j]=INF;
        dp[0][0]=0;

        for (int i=0; i<len; i++) for (int j=0; j<t; j++) //������,ö��ÿһ��״̬
                if (dp[i][j]!=INF && H[j].flag==false)  //��״̬�Ϸ�
                {
                    for (int k=0; k<size; k++) //ö�ٿ��ߵı�
                    {
                        if (H[j].next[k]->flag)
                            continue;
                        int add=(k !=ID[str[i]]);
                        dp[i+1][H[j].next[k]->id] = min(dp[i+1][H[j].next[k]->id], dp[i][j]+add);
                    }
                }
        int ans=-1;
        for (int i=0; i<t; i++)
            if (dp[len][i]!=INF && (ans==-1 || dp[len][i]<ans))
                ans = dp[len][i];
        return ans;
    }
} ac;

char str[1005],s[25];

int main ()
{
    int n,Cas=0;
    while(read(n)&&n)
    {
        ac.Init();
        for (int i=1; i<=n; i++)
            scanf("%s",s),ac.Insert(s);
        scanf("%s",str);
        ac.Build();
        printf("Case %d: %d\n",++Cas,ac.Deal(str));
    }
    return 0;
}

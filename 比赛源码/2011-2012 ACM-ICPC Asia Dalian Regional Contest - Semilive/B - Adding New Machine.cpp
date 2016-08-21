#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#define MAXN 50004

using namespace std;

struct Square
{
    int l,r,b,t;
}square[MAXN];

struct setNode
{
    int top;
    int bot;
    setNode(){}
    setNode(int t,int b):top(t),bot(b){}

    bool operator < (const setNode & o)const
    {
        return top < o.top;
    }
};

struct Node
{
    int top;
    int bot;
    int kind;
    int pos;

    Node(){}
    Node(int aa,int bb,int cc,int pp):top(aa),bot(bb),kind(cc),pos(pp){}

    bool operator < (const Node &o)const
    {
        return pos < o.pos;
    }
};

multiset<setNode> S;

vector<Node> V;

int w,h,n,m;

int main()
{
    while(~scanf("%d%d%d%d",&w,&h,&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            square[i].l = min(x1,x2);
            square[i].r = max(x1,x2);
            square[i].b = min(y1,y2);
            square[i].t = max(y1,y2);
        }

        V.clear();

        for(int i=1;i<=n;i++)
        {
            V.push_back(Node(square[i].t,square[i].b,1,square[i].l));
            V.push_back(Node(square[i].t,square[i].b,-1,square[i].r+1));
        }
        V.push_back(Node(1,h,1,w+1));

        sort(V.begin(),V.end());

        int xx = 0,pre = -1;
        long long ans = 0;
        S.clear();
        S.insert(setNode(0,0));
        S.insert(setNode(h+1,h+1));
        int width = h-m+1 > 0 ? h-m+1 : 0;

        while(xx < V.size())
        {
            while(xx+1 < V.size() && V[xx].pos == V[xx+1].pos) xx++;

            ans += (long long)width * (long long)(V[xx].pos - (pre == -1 ? 1 : V[pre].pos));
            for(int i=pre+1;i<=xx;i++)
            {
                if(V[i].kind == 1)
                {
                    multiset<setNode>::iterator It1 = S.upper_bound(setNode(V[i].top,V[i].bot));
                    multiset<setNode>::iterator It2 = --It1;++It1;
                    width -= It1->bot - It2->top - m > 0 ? It1->bot - It2->top - m : 0;
                    width += It1->bot - V[i].top - m > 0 ? It1->bot - V[i].top - m : 0;
                    width += V[i].bot - It2->top - m > 0 ? V[i].bot - It2->top - m : 0;
                    S.insert(setNode(V[i].top,V[i].bot));
                }
                else if(V[i].kind == -1)
                {
                    multiset<setNode>::iterator It1 = S.find(setNode(V[i].top,V[i].bot));if(It1 == S.end())while(1);
                    multiset<setNode>::iterator It2 = --It1;++It1;
                    multiset<setNode>::iterator It3 = ++It1;--It1;
                    width -= It3->bot - It1->top - m > 0 ? It3->bot - It1->top - m : 0;
                    width -= It1->bot - It2->top - m > 0 ? It1->bot - It2->top - m : 0;
                    width += It3->bot - It2->top - m > 0 ? It3->bot - It2->top - m : 0;
                    S.erase(It1);
                }
            }
            pre = xx;
            xx++;
        }
        //-------------------------------------------
        if(m == 1) goto Print;

        V.clear();

        for(int i=1;i<=n;i++)
        {
            V.push_back(Node(square[i].r,square[i].l,1,square[i].b));
            V.push_back(Node(square[i].r,square[i].l,-1,square[i].t+1));
        }
        V.push_back(Node(1,w,1,h+1));

        sort(V.begin(),V.end());

        xx = 0,pre = -1;
        S.clear();
        S.insert(setNode(0,0));
        S.insert(setNode(w+1,w+1));
        width = w-m+1 > 0 ? w-m+1 : 0;

        while(xx < V.size())
        {
            while(xx+1 < V.size() && V[xx].pos == V[xx+1].pos) xx++;

            ans += (long long)width * (long long)(V[xx].pos - (pre == -1 ? 1 : V[pre].pos));
            for(int i=pre+1;i<=xx;i++)
            {
                if(V[i].kind == 1)
                {
                    set<setNode>::iterator It1 = S.upper_bound(setNode(V[i].top,V[i].bot));
                    set<setNode>::iterator It2 = --It1;++It1;
                    width -= It1->bot - It2->top - m > 0 ? It1->bot - It2->top - m : 0;
                    width += It1->bot - V[i].top - m > 0 ? It1->bot - V[i].top - m : 0;
                    width += V[i].bot - It2->top - m > 0 ? V[i].bot - It2->top - m : 0;
                    S.insert(setNode(V[i].top,V[i].bot));
                }
                else if(V[i].kind == -1)
                {
                    set<setNode>::iterator It1 = S.find(setNode(V[i].top,V[i].bot));
                    set<setNode>::iterator It2 = --It1;++It1;
                    set<setNode>::iterator It3 = ++It1;--It1;
                    width -= It3->bot - It1->top - m > 0 ? It3->bot - It1->top - m : 0;
                    width -= It1->bot - It2->top - m > 0 ? It1->bot - It2->top - m : 0;
                    width += It3->bot - It2->top - m > 0 ? It3->bot - It2->top - m : 0;
                    S.erase(It1);
                }
            }
            pre = xx;
            xx++;
        }
        Print:printf("%lld\n",ans);
    }
    return 0;
}
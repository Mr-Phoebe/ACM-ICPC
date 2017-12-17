#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

struct Rec
{
    int l,r,t,b;
};

int in(int x,int y,Rec r)
{
    if(x > r.l && x < r.r && y < r.t && y > r.b) return -1;
    if(x >= r.l && x <= r.r && y <= r.t && y >= r.b) return 0;
    return 1;
}

int cross(Rec a,Rec b)
{
    if(in(a.l,a.b,b) == -1 && in(a.l,a.t,b) == -1 && in(a.r,a.b,b) == -1 && in(a.r,a.t,b) == -1) return (b.r-b.l) * (b.t-b.b);
    if(in(b.l,b.b,a) == -1 && in(b.l,b.t,a) == -1 && in(b.r,b.b,a) == -1 && in(b.r,b.t,a) == -1) return (a.r-a.l) * (a.t-a.b);

    if(in(a.l,a.b,b) == 1 && in(a.l,a.t,b) == 1 && in(a.r,a.b,b) == 1 && in(a.r,a.t,b) == 1)
        if(in(b.l,b.b,a) == 1 && in(b.l,b.t,a) == 1 && in(b.r,b.b,a) == 1 && in(b.r,b.t,a) == 1)
        return (b.r-b.l) * (b.t-b.b) + (a.r-a.l) * (a.t-a.b);

    return -1;
}

Rec A,B;

int n;
int x[35],y[35];

map<int,int> X;
map<int,int> Y;

bool gao1(int p1,int p2,int p3,int p4)
{
    X.clear();
    Y.clear();
    if(X.find(x[p1]) == X.end()) X.insert(make_pair(x[p1],0));
    X[x[p1]]++;
    if(X.find(x[p2]) == X.end()) X.insert(make_pair(x[p2],0));
    X[x[p2]]++;
    if(X.find(x[p3]) == X.end()) X.insert(make_pair(x[p3],0));
    X[x[p3]]++;
    if(X.find(x[p4]) == X.end()) X.insert(make_pair(x[p4],0));
    X[x[p4]]++;
    if(Y.find(y[p1]) == Y.end()) Y.insert(make_pair(y[p1],0));
    Y[y[p1]]++;
    if(Y.find(y[p2]) == Y.end()) Y.insert(make_pair(y[p2],0));
    Y[y[p2]]++;
    if(Y.find(y[p3]) == Y.end()) Y.insert(make_pair(y[p3],0));
    Y[y[p3]]++;
    if(Y.find(y[p4]) == Y.end()) Y.insert(make_pair(y[p4],0));
    Y[y[p4]]++;

    if(X.size() == 2 && Y.size() == 2 && (X.begin())->second == 2 && (Y.begin())->second == 2)
    {
        A.l = min(min(x[p1],x[p2]),min(x[p3],x[p4]));
        A.r = max(max(x[p1],x[p2]),max(x[p3],x[p4]));
        A.b = min(min(y[p1],y[p2]),min(y[p3],y[p4]));
        A.t = max(max(y[p1],y[p2]),max(y[p3],y[p4]));
        return true;
    }
    return false;
}

bool gao2(int p1,int p2,int p3,int p4)
{
    X.clear();
    Y.clear();
    if(X.find(x[p1]) == X.end()) X.insert(make_pair(x[p1],0));
    X[x[p1]]++;
    if(X.find(x[p2]) == X.end()) X.insert(make_pair(x[p2],0));
    X[x[p2]]++;
    if(X.find(x[p3]) == X.end()) X.insert(make_pair(x[p3],0));
    X[x[p3]]++;
    if(X.find(x[p4]) == X.end()) X.insert(make_pair(x[p4],0));
    X[x[p4]]++;
    if(Y.find(y[p1]) == Y.end()) Y.insert(make_pair(y[p1],0));
    Y[y[p1]]++;
    if(Y.find(y[p2]) == Y.end()) Y.insert(make_pair(y[p2],0));
    Y[y[p2]]++;
    if(Y.find(y[p3]) == Y.end()) Y.insert(make_pair(y[p3],0));
    Y[y[p3]]++;
    if(Y.find(y[p4]) == Y.end()) Y.insert(make_pair(y[p4],0));
    Y[y[p4]]++;

    if(X.size() == 2 && Y.size() == 2 && (X.begin())->second == 2 && (Y.begin())->second == 2)
    {
        B.l = min(min(x[p1],x[p2]),min(x[p3],x[p4]));
        B.r = max(max(x[p1],x[p2]),max(x[p3],x[p4]));
        B.b = min(min(y[p1],y[p2]),min(y[p3],y[p4]));
        B.t = max(max(y[p1],y[p2]),max(y[p3],y[p4]));
        return true;
    }
    return false;
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(n == 0) break;

        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);

        int ans = -1;

        for(int a1 = 1;a1 <=n;a1++)
            for(int b1 = a1+1;b1 <= n;b1++)
            if(a1 != b1)
                for(int c1 = b1+1;c1 <= n;c1++)
                if(c1 != a1 && c1 != b1)
                    for(int d1 = c1+1;d1 <= n;d1++)
                    if(d1 != c1 && d1 != b1 && d1 != a1)
                    {
                        if(gao1(a1,b1,c1,d1))
                        {
                            for(int a2 = 1;a2 <=n;a2++)
                                if(a2 != d1 && a2 != c1 && a2 != b1 && a2 != a1)
                                    for(int b2 = a2+1;b2 <= n;b2++)
                                    if(b2 != d1 && b2 != c1 && b2 != b1 && b2 != a1 && a2 != b2)
                                        for(int c2 = b2+1;c2 <= n;c2++)
                                        if(c2 != d1 && c2 != c1 && c2 != b1 && c2 != a1 && c2 != a2 && c2 != b2)
                                            for(int d2 = c2+1;d2 <= n;d2++)
                                            if(d2 != d1 && d2 != c1 && d2 != b1 && d2 != a1 && d2 != c2 && d2 != b2 && d2 != a2)
                                            {
                                                if(gao2(a2,b2,c2,d2))
                                                {
                                                    ans = max(ans,cross(A,B));
                                                }
                                            }

                        }
                    }
        if(ans == -1) printf("imp\n");
        else printf("%d\n",ans);
    }
    return 0;
}

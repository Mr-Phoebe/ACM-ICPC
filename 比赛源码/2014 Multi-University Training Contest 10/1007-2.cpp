#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const double PI = acos(-1.);
const double eps = 1e-8;
const double sqrt3 = sqrt(3);
int dcmp(double val)
{
    return val<eps?val<-eps?-1:0:1;
}
#define mul 1
struct pnt
{
    double x, y;
    pnt() {}
    pnt(double _x, double _y) : x(_x), y(_y) {}
    pnt operator - (pnt p) {return pnt(x - p.x, y - p.y);}
    pnt operator + (pnt p) {return pnt(x + p.x, y + p.y);}
    pnt operator / (double d){return pnt(x / d, y / d);}
    pnt operator * (double d){return pnt(x * d, y * d);}
    bool operator < (const pnt&p)const{return dcmp(x-p.x)==0?dcmp(y-p.y)<=0:dcmp(x-p.x)<=0;}
    double operator ^ (pnt p) {return x * p.y - y * p.x;} //叉积
    double operator | (pnt p) {return x * p.x + y * p.y;} //点积
    double len(){return hypot(x,y);}
    double arc(){return atan2(y,x);}
    pnt rotate(){return pnt(-y,x);}
    pnt rotate(double arc){return pnt(x*cos(arc)-y*sin(arc),x*sin(arc)-y*cos(arc));}
    double dis(pnt p){return (*this-p).len();}
    void scan() {scanf("%lf%lf", &x, &y);x*=mul;y*=mul;}
    void print(){printf("%f %f\n",x,y);}
};

int ConvexHull(pnt *t,pnt *f,int n)
{
    sort(f,f+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&dcmp((t[m-1]-t[m-2])^(f[i]-t[m-2]))<=0)m--;
        t[m++]=f[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&dcmp((t[m-1]-t[m-2])^(f[i]-t[m-2]))<=0)m--;
        t[m++]=f[i];
    }
    return m-1;
}

int pnt_on_seg(pnt p,pnt A1,pnt A2)//-1,0,1 inside,on,outside
{
    return dcmp((p-A1)|(p-A2));
}

pnt line_sec_line(pnt A1,pnt A2,pnt B1,pnt B2)
{
    double p=(B2-B1)^(A1-B1),q=(B2-B1)^(A2-B1);//p==q平行
    return (A1*q-A2*p)/(q-p);
}

int line_sec_cir(pnt a,pnt b,pnt o,double r,pnt&r1,pnt&r2)
{
    pnt d=a-b;
    pnt c=o+d.rotate();
    c = line_sec_line(a,b,c,o);
    double val= c.dis(o);
    val = r*r - val*val;
    if(dcmp(val)<0) return 0;
    if(dcmp(val)==0)
    {
        r1=c;
        return 1;
    }
    val = sqrt(val)/a.dis(b);
    r1 = c + d*val;
    r2 = c - d*val;
    return 2;
}
double che(pnt&a,double r)
{
    return asin(r/a.len()*sqrt3*0.5)-PI/6;
}
vector< pair<double,int> >use;
int flag,cnt;
void check(pnt&a,pnt&b,double R)
{
    double th1=che(a,R),th2=che(b,R);
    double t1=a.arc(),t2=b.arc();
    if(t1-t2>PI)t2+=PI*2;
    else if(t2-t1>PI)t1+=PI*2;
    double l=max(t1-th1,t2-th2)-eps,r=min(t1+th1,t2+th2)+eps;
    //if(dcmp(r-l-PI/3)==0)return;
    if(r<l)
    {
        flag=0;
    }
    cnt++;
    for(int i=0;i<6;i++)
    {
        l+=PI/3,r+=PI/3;
        if(l>=PI)l-=2*PI;
        if(r>=PI)r-=2*PI;
        use.push_back(make_pair(l,-1));
        use.push_back(make_pair(r,1));
        if(r<l)cnt--;
    }
}
pnt a[100010],r[100010];
int main(int argv,char **args)
{
    int ti;scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        int m,R;scanf("%d%d",&m,&R);
        for(int i=0;i<m;i++)
        {
            a[i].scan();
        }
        flag=1;
        int n=ConvexHull(r,a,m);
        pnt ta,tb;
        cnt=0;
        use.clear();
        for(int i=0;i<n&&flag;i++)
        {
            if(dcmp(r[i].len()-R*sqrt3)>0)flag=0;
            if(dcmp(r[(i+1)%n].len()-R*sqrt3)>0)flag=0;
            int a1=dcmp(r[i].len()-R),a2=dcmp(r[(i+1)%n].len()-R);
            int w=line_sec_cir(r[i],r[(i+1)%n],pnt(0,0),R+eps,ta,tb);
            if(a1>0&&a2>0)
            {
                if(w==0)check(r[i],r[(i+1)%n],R);
                else
                {
                    int a=pnt_on_seg(ta,r[i],r[(i+1)%n])==-1;
                    int b=pnt_on_seg(tb,r[i],r[(i+1)%n])==-1;
                    if(a&&b)check(r[i],ta,R),check(tb,r[(i+1)%n],R);
                    else if(a)check(r[i],ta,R),check(ta,r[(i+1)%n],R);
                    else if(b)check(r[i],ta,R),check(tb,r[(i+1)%n],R);
                    else check(r[i],r[(i+1)%n],R);
                }
            }
            else if(a1>0)check(r[i],ta,R);
            else if(a2>0)check(tb,r[(i+1)%n],R);
        }
        double arc;
        if(flag)
        {
            sort(use.begin(),use.end());
            int l=0,h=0,now=0;
            for(int i=0;i<use.size();i++)
            {
                now-=use[i].second;
                if(h==cnt)
                {
                    arc=use[i].first/2+use[(i+1)%use.size()].first/2;
                    break;
                }
                h=max(now,h);
            }
            if(h!=cnt)flag=0;
            if(h>cnt)printf("ERROR!\n");
        }
//        if(flag)
//        {
//            if(vvs!=-1&&vvs!=ca)continue;
//            printf("%d %f\n",R,arc);
//            for(int i=0;i<n;i++)
//            {
//                r[i].print();
//            }
//        }
        printf("Case #%d: %s.\n",ca,flag?"Succeeded":"Failed");
    }
}

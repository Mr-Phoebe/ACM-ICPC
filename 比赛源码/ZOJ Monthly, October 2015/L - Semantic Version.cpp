#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

string a,b;
vector<string> va,vb;

int worka(char x,char y,int pos)
{
    if(pos >= a.size()) return pos;
    string tmp;
    while(1)
    {
        if(pos >= a.size() || a[pos] == x)
        {
            va.push_back(tmp);
            tmp.clear();
            return pos;
        }
        if(a[pos] == y)
        {
            pos++;
            va.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.append(1,a[pos]);
        pos++;
    }
}

int workb(char x,char y,int pos)
{
    if(pos >= b.size()) return pos;
    string tmp;
    while(1)
    {
        if(pos >= b.size() || b[pos] == x)
        {
            vb.push_back(tmp);
            tmp.clear();
            return pos;
        }
        if(b[pos] == y)
        {
            pos++;
            vb.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.append(1,b[pos]);
        pos++;
    }
}

bool is_int(string x)
{
    for(int i=0;i<x.size();i++)
    if(! (x[i] >= '0' && x[i] <= '9')) return false;

    return true;
}

int cmp(string a,string b)
{
    if(a.size() > b.size()) return 1;
    if(a.size() < b.size()) return -1;
    for(int i=0;i<=a.size();i++)
    {
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    return 0;
}

int comp()
{
    for(int i=0;i<3;i++)
    {
        if(cmp(va[i],vb[i]) == -1) return -1;
        if(cmp(va[i],vb[i]) == 1) return 1;
    }

    if(va.size() == 3 && vb.size() == 3) return 1;
    if(va.size() == 3) return 1;
    if(vb.size() == 3) return -1;

    for(int i=3;i<min(va.size(),vb.size());i++)
    {
        if(is_int(va[i]) && !is_int(vb[i])) return -1;
        if(!is_int(va[i]) && is_int(vb[i])) return 1;
        if(is_int(va[i]) && is_int(vb[i]))
        {
            if(cmp(va[i],vb[i]) == -1) return -1;
            if(cmp(va[i],vb[i]) == 1) return 1;
        }
        if(!is_int(va[i]) && !is_int(vb[i]))
        {
            if(va[i] < vb[i]) return -1;
            if(va[i] > vb[i]) return 1;
        }
    }

    if(va.size() < vb.size()) return -1;
    if(va.size() > vb.size()) return 1;
    return 1;
}

int main()
{
    while(cin>>a>>b)
    {
        va.clear();
        vb.clear();

        int posa = worka('-','.',0);
        int posb = workb('-','.',0);

        worka('\0','.',posa+1);
        workb('\0','.',posb+1);
//for(int i=0;i<va.size();i++) cout<<va[i]<<endl;
//for(int i=0;i<vb.size();i++) cout<<vb[i]<<endl;
//cout<<endl;
        int ans = comp();

        if(ans == -1) cout<<"Wow! Such feature! Very smart! I'm excited!\n";
        else cout<<"I'm angry!\n";
    }
    return 0;
}

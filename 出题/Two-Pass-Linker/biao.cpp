//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#include <list>
#include <ctime>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <numeric>
#include <regex>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF)
        c = getchar();
    if(c == EOF)
        return false;
    if(c == '-')
        c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9')
        x *= 10, x += (c - '0'),c = getchar();
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
    if(!len)
        data[len++] = 0;
    while(len--)
        putchar(data[len]+48);
}
//-----------------------------------

int N;
int linenum=1;
int currentlinenum=1;
int modulenum=0;
int lineoffset=0;
int charoffset=1;
int charcount=0;

map<string,int> symboltable;
map<string,int> symbolusecount;
vector<string> multiple_defined_symbols;
vector<string> current_use_list;
vector<vector<string> > use_list;
map<string,int> current_def_list;
vector<map<string,int> > def_list;
map<string,bool> is_symbol_used_tmp;
vector<pair<string, int> > current_inst_list;
vector<vector<pair<string, int> > > inst_list;

void reset()
{
    linenum=1;
    currentlinenum=1;
    modulenum=0;
    lineoffset=0;
    charoffset=1;

    symboltable.clear();
    symbolusecount.clear();
    multiple_defined_symbols.clear();
    use_list.clear();
    def_list.clear();
    inst_list.clear();
}

void read_def()
{
    //cout<<"...read def"<<endl;
    string str;
    int val;
    cin>>str>>val;
    if(symboltable.find(str)==symboltable.end())//not found
    {
        symboltable[str] = lineoffset + val;
        current_def_list[str] = lineoffset + val;
        symbolusecount[str] = 0;
    }
    else //found
    {
        multiple_defined_symbols.push_back(str);
    }
}

void read_def_list()
{
    int defcount;
    read(defcount);
    for(int i = 0; i < defcount; i++)
    {
        read_def();
    }
}

void read_use_list()
{
    int usecount;
    string s;
    read(usecount);
    current_use_list.clear();
    for(int i = 0; i<usecount; i++)
    {
        cin>>s;
        current_use_list.push_back(s);
    }
    use_list.push_back(current_use_list);
}

void read_inst_list()
{
    //cout<<"...read inst list"<<endl;
    int codecount, val;
    string type;
    read(codecount);
    current_inst_list.clear();
    for(int i = 0; i < codecount; i++)
    {
        cin>>type;
        cin>>val;
        current_inst_list.push_back(make_pair(type, val));
    }
    inst_list.push_back(current_inst_list);
    lineoffset+=codecount;
}

void set_inst(string type, int instr)
{
    bool is_defined = true;
    bool is_legal_length = true;
    bool is_legal_absaddr = true;
    bool is_legal_relaaddr = true;

    if(instr>9999)
    {
        instr=9999;
        cout << setfill('0') << setw(4) << instr<<endl;
        cout << "Warning 1"<<endl;
    }
    else
    {

        if(type.compare("R") == 0)
        {
            instr = instr+lineoffset;
        }
        if(type.compare("E") == 0)
        {
            int oprand = instr % 1000;
            if(oprand >= current_use_list.size())
            {
                is_legal_length = false;
            }
            else
            {
                string s = current_use_list[oprand];
                is_symbol_used_tmp[s] = true;
                if(symboltable.find(s) == symboltable.end())//not found
                {
                    is_defined = false;
                }
                else    //found
                {
                    symbolusecount[s] += 1;
                    instr =instr/1000 * 1000+ symboltable[s];
                }
            }
        }

        if(!is_defined)
        {
            cout << "Error 2"<<endl;
        }
        else if(!is_legal_length)
        {
            cout << "Error 2"<<endl;
        }
        else
        {
            cout << setfill('0') << setw(4) << instr<<endl;
        }
    }
}



void first_pass()
{
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        read_def_list();
        read_use_list();
        read_inst_list();
    }
}

void second_pass()
{
    lineoffset = 0;
    for(int i = 0; i < N; i++)
    {
        current_use_list = use_list[i];
        for(int j = 0; j < current_use_list.size(); j++)
        {
            is_symbol_used_tmp[current_use_list[j]] = false;
        }
        for(int j = 0; j < inst_list[i].size(); j++)
        {
            set_inst(inst_list[i][j].first, inst_list[i][j].second);
        }
        for(auto const &ent1 : is_symbol_used_tmp)
        {
            if(!ent1.second)
            {
                cout << "Warning 2: "<<ent1.first<<endl;
            }
        }
        is_symbol_used_tmp.clear();
    }
    for(auto const &ent1 : symbolusecount)
    {
        if(ent1.second == 0)
        {
            cout << "Warning 3: "<<ent1.first<<endl;
        }
    }
}

void print_symbol_table()
{
    //cout<<"Symbol Table"<<endl;
    for(map<string,int>::iterator it=symboltable.begin(); it!=symboltable.end(); ++it)
    {
        if(find(multiple_defined_symbols.begin(), multiple_defined_symbols.end(),it->first) != multiple_defined_symbols.end())
        {
            cout<<"Error 1: "<<it->first<<endl;
        }
    }
}

int main(int argc, char* argv[])
{
    freopen("data1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin>>T;
    while(T--)
    {
        first_pass();
        print_symbol_table();
        second_pass();
        reset();
    }
    return 0;
}

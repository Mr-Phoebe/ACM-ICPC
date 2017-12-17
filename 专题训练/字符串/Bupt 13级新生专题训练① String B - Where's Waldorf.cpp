#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
using namespace std;  
  
char table[50][50];  
char word[50];  
const int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };  
const int dy[] = { 0, 0, -1, 1, -1, -1, 1, 1 };  
int T;  
int m,n,k;  
  
int f(int x, int y) //从table[x][y]开始向8个方向搜索是否有相同的字符串  
{  
    for(int d=0; d<8; d++)  
    {  
        int newx=x, newy=y;  
        int ok=1;  
        for(int i=1; i<strlen(word); i++)  
        {  
            newx = newx + dx[d];  
            newy = newy + dy[d];  
            if(newx>=0 && newx<m && newy>=0 && newy<n)  
            {  
                if(table[newx][newy]!=word[i])  
                {  
                    ok=0;  
                    break;  
                }  
            }  
            else  
            {  
                ok=0;  
                break;  
            }  
        }  
        if(ok) return 1;  
    }  
    return 0;  
}  
  
int main()  
{  
    cin >> T;  
    while(T--)  
    {  
        cin >> m >> n;  
        for(int i=0; i<m; i++)  
            for(int j=0; j<n; j++)  
            {  
                cin >> table[i][j];  
                if(table[i][j]>='A' && table[i][j]<='Z')  
                    table[i][j]=table[i][j]-'A'+'a';  
            }  
  
        cin >> k;  
        for(int i=0; i<k; i++)  
        {  
            cin >> word;  
            for(int j=0; j<strlen(word); j++)  
                if(word[j]>='A' && word[j]<='Z')  
                    word[j]=word[j]-'A'+'a';  
            int topx, lefty, find=0;  
            for(int a=0; a<m; a++)  
            {  
                if(find) break;  
                for(int b=0; b<n; b++)  
                {  
                    if(word[0]==table[a][b])  
                    {  
                        if(f(a,b))  
                        {  
                            topx=a; lefty=b; find=1;  
                            break;  
                        }  
                    }  
                }  
            }  
            cout << topx+1 << ' ' << lefty+1 << endl;  
        }  
        if(T) cout << endl;  
    }  
  
    return 0;  
}  
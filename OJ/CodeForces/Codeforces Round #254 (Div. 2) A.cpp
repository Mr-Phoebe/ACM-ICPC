#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n,m;
    cin >> n >>m;
    vector<string> board(n,string(m,'B'));
    for(int i = 0 ; i < n; ++ i){
        for(int j = 0 ; j < m ; ++j){
            if(i%2){
                if(j%2 == 0) board[i][j] = 'W';
            }else{
                if(j%2) board[i][j] ='W';
            }
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0 ; j < m; ++ j){
            char ch;
            cin >>ch;
            if(ch == '-') board[i][j] = '-';
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
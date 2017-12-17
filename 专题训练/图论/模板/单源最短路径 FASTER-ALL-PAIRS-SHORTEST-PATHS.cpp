#include <cstdlib>
#include <iostream>
#define N 9999
using namespace std;
int l[5][5] = {{0, 3, 8, N, -4}, {N, 0, N, 1, 7}, {N, 4, 0, N, N}, {2, N, -5, 0, N}, {N, N, N, 6, 0}}; 
//int l[6][6] = {{0, N, N, N, -1, N}, {1, 0, N, 2, N, N}, {N, 2, 0, N, N, -8}, {-4, N, N, 0, 3, N}, {N, 7, N, N, 0, N}, {N, 5, 10, N, N, 0}};
int w[5][5];
void print()
{
     for(int i = 0; i < 5; i++)
     {
             for(int j = 0; j < 5; j++)
                     cout << w[i][j] << " ";
             cout << endl;
     }
}

void ExtendShortestPath()
{
     int t;
     for(int i = 0; i < 5; i++)
             for(int j = 0; j < 5; j++)
             {
                     t = N;
                     for(int k = 0; k < 5; k++)
                     {
                             
                             if(l[i][j] > l[i][k] + l[k][j] && t > l[i][k] + l[k][j])
                             {
                                        w[i][j] = l[i][k] + l[k][j];
                                        t = w[i][j];
                             }
                     }
             }
}

int main(int argc, char *argv[])
{
    for(int i = 0; i < 5; i++)
    {
            for(int j = 0; j < 5; j++)
            {
                            w[i][j] = l[i][j];
            }
    }
    int m;
    m = 1;
    while(m < 4)
    {
            ExtendShortestPath();
            m *= 2;
            print();
            for(int i = 0; i <5; i++)
            {
                    for(int j = 0; j < 5; j++)
                    {
                            l[i][j] = w[i][j];
                    }
            }
            cout << endl;
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
// UVa11235 Frequent Values
// Rujia Liu
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100000 + 5;
const int maxlog = 20;

// 区间最*大*值
struct RMQ {
  int d[maxn][maxlog];
  void init(const vector<int>& A) {
    int n = A.size();
    for(int i = 0; i < n; i++) d[i][0] = A[i];
    for(int j = 1; (1<<j) <= n; j++)
      for(int i = 0; i + (1<<j) - 1 < n; i++)
        d[i][j] = max(d[i][j-1], d[i + (1<<(j-1))][j-1]);
  }

  int query(int L, int R) {
    int k = 0;
    while((1<<(k+1)) <= R-L+1) k++; // 如果2^(k+1)<=R-L+1，那么k还可以加1
    return max(d[L][k], d[R-(1<<k)+1][k]);
  }
};

int a[maxn], num[maxn], left[maxn], right[maxn];
RMQ rmq;
int main() {
  int n, q;
  while(scanf("%d%d", &n, &q) == 2) {
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n] = a[n-1] + 1; // 哨兵
    int start = -1;
    vector<int> count;
    for(int i = 0; i <= n; i++) {
      if(i == 0 || a[i] > a[i-1]) { // 新段开始
        if(i > 0) {
          count.push_back(i - start);
          for(int j = start; j < i; j++) {
            num[j] = count.size() - 1; left[j] = start; right[j] = i-1;
          }
        }
        start = i;
      }
    }
    rmq.init(count);
    while(q--) {
      int L, R, ans;
      scanf("%d%d", &L, &R); L--; R--;
      if(num[L] == num[R]) ans = R-L+1;
      else {
        ans = max(R-left[R]+1, right[L]-L+1);
        if(num[L]+1 < num[R]) ans = max(ans, rmq.query(num[L]+1, num[R]-1));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}


/*Problem F: Frequent values

You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input Specification

The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the query.

The last test case is followed by a line containing a single 0.

Output Specification

For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Sample Input

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output

1
4
3
*/
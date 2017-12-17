#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100010;
typedef long long LL;

double findMedianSortedArrays(LL nums1[], LL nums2[], int n, int m) {
    int l = 0, r = n+1;
    int m1, m2;

    while(l < r) {
        m1 = (l+r)/2;
        m2 = (n+m)/2-m1;
        
        if(m2 < 0) {
            r = m1;
        } else if(m2 > m) {
            l = m1+1;
        } else if(m1 != n && m2 && nums1[m1] < nums2[m2-1]) {
            l = m1+1;
        } else if(m2 != m && m1 && nums1[m1-1] > nums2[m2]) {
            r = m1;
        } else {
            l = r = m1;
        }
    }
    m1 = l; m2 = (n+m)/2-m1;
    if((n+m)%2 == 0) {
        long long ll, rr;
        if(m1) {
            ll = nums1[m1-1];
            if(m2) ll = max(ll, nums2[m2-1]);
        } else {
            ll = nums2[m2-1];
        }
        if(m1 != n) {
            rr = nums1[m1];
            if(m2 != m) {
                rr = min(rr, nums2[m2]);
            }
        } else {
            rr = nums2[m2];
        }
        return (double)(ll+rr)/2;
    } else {
        long long rr;
        if(m1 != n) {
            rr = nums1[m1];
            if(m2 != m) {
                rr = min(rr, nums2[m2]);
            }
        } else {
            rr = nums2[m2];
        }
        return rr;
    }
}

long long a[maxn];
int n, m;

int main()
{
	//freopen("1001.in","r",stdin);
    //freopen("check2.out","w",stdout);
	int T_T, l1, l2, r1, r2;
	cin >> T_T;
	while(T_T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", a+i);
		}
		while(m--)
		{
			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			printf("%.1f\n", findMedianSortedArrays(a+l1, a+l2, r1-l1+1, r2-l2+1));
		}
	}
	return 0;
}

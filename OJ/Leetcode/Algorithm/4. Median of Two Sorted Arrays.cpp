class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(), m = nums1.size();
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (divide(nums1, 0, m ,nums2, 0, n, l) + divide(nums1, 0, m, nums2, 0, n, r)) / 2.0;
    }
private:
    int divide(vector<int>& a, int p1, int l1, vector<int>& b, int p2, int l2, int k)
    {
        if(l1 > l2)
            return divide(b, p2, l2, a, p1, l1, k);
        if(l1 == 0)
            return b[p2+k-1];
        if (k == 1)
            return min(a[p1], b[p2]);
        int n1 = min(l1, k/2), n2 = min(l2, k/2);
        if(a[p1+n1-1] > b[p2+n2-1])
            return divide(a, p1, l1, b, p2+n2, l2-n2, k-n2);
        else
            return divide(a, p1+n1, l1-n1, b, p2, l2, k-n1);
    }
};

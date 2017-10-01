class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sum(n,0);
        vector<int> l  (n,0);
        vector<int> li  (n,0);
        for(int i=0;i<k;i++)
            sum[0]+=nums[i];
        l[0]=sum[0];
        li[0]=0;
        for(int i=1;i+k<n;i++){
            sum[i]=sum[i-1]-nums[i-1]+nums[i+k-1];
            l[i]=max(l[i-1],sum[i]);
            if(l[i-1]<sum[i])
                li[i]=i;
            else
                li[i]=li[i-1];
        }
        vector<int> r  (n,0);
        vector<int> ri  (n,0);
        r[n-k]=0;
        ri[n-k]=n-k;
        int tmp=0;
        for(int i=0;i<k;i++){
            r[n-k]+=nums[n-i-1];
            tmp+=nums[n-i-1];
        }
        for(int i=n-k-1;i>=0;i--){
            tmp=tmp-nums[i+k]+nums[i];
            r[i]=max(r[i+1],tmp);
            if(r[i+1]<=tmp)
                ri[i]=i;
            else
                ri[i]=ri[i+1];
            
        }
        vector<int> v(3,0);
        int ans=-1;
        for(int i=k;i+k<n;i++){
            if(ans<sum[i]+l[i-k]+r[i+k]){
                v[0]=li[i-k];
                v[1]=i;
                v[2]=ri[i+k];
                ans=sum[i]+l[i-k]+r[i+k];
            }
        }
        return v;
    }
};
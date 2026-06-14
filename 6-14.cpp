class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> f(n,0);
        f[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                f[i]=max(f[j]+nums[i],f[i]);
            }
            f[i]=max(f[i],nums[i]);
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,f[i]);
        }

        return res;
    }
};
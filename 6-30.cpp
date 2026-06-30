class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int> f(n+1);

        f[0]=nums[0];
        if(n>=2) f[1]=nums[1];

        for(int i=2;i<n;i++)
        {
            f[i]=nums[i];
            for(int j=0;j<=i-2;j++)
            {
                f[i]=max(f[i],f[j]+nums[i]);
            }
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,f[i]);
        }
        return res;
    }
};
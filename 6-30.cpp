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

//x2，还是不会
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        word1=" "+word1;
        word2=" "+word2;
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));

        for(int i=0;i<=m-1;i++) f[0][i]=i;
        for(int i=0;i<=n-1;i++) f[i][0]=i;

        for(int i=1;i<=n-1;i++)
        {
            for(int j=1;j<=m-1;j++)
            {
                f[i][j]=min(f[i-1][j],f[i][j-1])+1;
                if(word1[i]==word2[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
                else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
            }
        }

        return f[n-1][m-1];
    }   
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>> f(n+10,vector<int>(m+10,0));

        // if(text1[0]==text2[0]) f[0][0]=1;
        // else f[0][0]=0;

        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(text1[i]==text2[j])
                {
                    f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+1);
                }
                else
                {
                    f[i+1][j+1]=max(f[i+1][j+1],f[i][j+1]);
                    f[i+1][j+1]=max(f[i+1][j+1],f[i+1][j]);
                }
                res=max(res,f[i+1][j+1]);
            }
        }

        return res;
    }
};
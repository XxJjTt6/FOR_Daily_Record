class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.size();
        vector<vector<bool>> f(n,vector(n,false));
        string res="";
        int mlen=0;

        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j) f[i][j]=true;
                else if(j-i+1==2)
                {
                    f[i][j]=(s[i]==s[j]);
                }
                else if(i+1<n&&j-1>=0) f[i][j]=f[i+1][j-1]&&(s[i]==s[j]);

                if(f[i][j]==true)
                {
                    if(j-i+1>mlen)
                    {
                        mlen=j-i+1;
                        res=s.substr(i,j-i+1);
                    }
                }
            }
        }

        return res;
    }
};


// 暴力写法，没思路
// class Solution {
// public:
//     string res;
//     int mlen;
//     int n;

//     bool judge(int l,int r,string s)
//     {
//         bool flag=true;
//         while(l<=r&&l>=0&&r<=n-1)
//         {
//             if(s[l]!=s[r])
//             {

//                 flag=false;
//                 break;
//             }
//             if(r-l+1>mlen)
//             {
//                 mlen=r-l+1;
//                 res=s.substr(l,r-l+1);
//             }
//             l--;
//             r++;
//         }
//         return flag;
//     }   

//     string longestPalindrome(string s) 
//     {
//         n=s.size();
//         res=s[0];
//         mlen=1;

//         for(int i=0;i<n;i++)
//         {
//             if(i-1>=0&&i+1<n) judge(i-1,i+1,s);
//             if(i+1<n) judge(i,i+1,s);
//         }
//         return res;
//     }
// };
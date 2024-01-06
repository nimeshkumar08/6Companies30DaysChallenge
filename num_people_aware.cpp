class Solution {
public:
   int mod = 1000000007;
    int solve(int s,int f,int d,int n,vector<int>& dp){
        if(dp[s] != -1)
        {
            return dp[s];
        }
        int ans =0;
        for(int i = s;i<= n;i++)
        {
            if(i-s == f)
            {
                ans = ans-1;
                break;
            }
            if(i-s>= d){
                ans = (ans+1)%mod;
                ans += solve(i,f,d,n,dp)%mod;
            }
        }
        return dp[s] = ans;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
       vector<int> dp(n+1,-1);
        return (solve(1,forget,delay,n,dp)+1)%mod;
        
    }
};
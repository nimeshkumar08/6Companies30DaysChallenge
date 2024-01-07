class Solution {
public:
    long long int mod = 1e9+7;
    int f(int idx, int k, int& endPos, int& lower, vector<vector<int>>& dp){
        if(k == 0)
        {
            if(idx == endPos)
            {
                return 1;
            }
            return 0;
        }
        int i;
        if(lower > 0)
        {
            i = idx-lower;
        }
        else if(lower < 0)
        {
            i = idx+abs(lower);
        }
        else{
            i = idx;
        }
        if(dp[i][k] != -1)
        {
            return dp[i][k];
        }
        int first = f(idx+1, k-1, endPos, lower, dp); 
        int second = f(idx-1, k-1, endPos, lower, dp); 
        return dp[i][k] = (first+second)%mod; 
        
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int lower = startPos - k;
        int upper = startPos + k;
        vector<vector<int>> dp(upper-lower+1, vector<int>(k+1, -1));
        return f(startPos, k, endPos, lower, dp);
    }
};
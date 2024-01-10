class Solution 
{
public:
    bool ispalindrome(string s)
    {
        int i = 0,j = s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s , string &s1 , string &s2 , int i , int &ans)
    {
        if(i>=s.size())
        {
            if(ispalindrome(s1) && ispalindrome(s2))
            {
                int x=s1.size()*s2.size();
                ans=max(ans,x);
            }
            return ;
        }
        solve(s,s1,s2,i+1,ans);
        s1.push_back(s[i]);
        solve(s,s1,s2,i+1,ans);
        s1.pop_back();
        s2.push_back(s[i]);
        solve(s,s1,s2,i+1,ans);
        s2.pop_back();
    }
    int maxProduct(string s) 
    {
        string s1="";
        string s2="";
        int ans=0;
        solve(s,s1,s2,0,ans);
        return ans;
    }
};
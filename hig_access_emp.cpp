class Solution {
public:
    static bool cmp(vector<string>&v1 , vector<string>&v2)
    {
        return (v1[1] < v2[1]);
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        sort(at.begin(), at.end(), cmp);
        int n = at.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n-1;i++)
        {
            int first = stoi(at[i][1]);
            string ch = at[i][0];
            int range = first+100-1;
            int count=1;
            for(int j=i+1;j<n;j++)
            {
                int val = stoi(at[j][1]);
                if(at[j][0]==ch && val<=range && val>=first)
                {
                    count++;
                }
            }
            if(count>=mp[ch])
            {
                mp[ch]=count;
            }
        }
        vector<string>ans;
        for(auto it : mp)
        {
            if(it.second>=3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
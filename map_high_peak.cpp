class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& data) {
        int m = data.size();
        int n = data[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue <pair<int,int>> q;
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(data[i][j]==1)
                {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x+1<m)
            {
                if(ans[x+1][y]==-1)
                {
                    ans[x+1][y] = ans[x][y]+1;
                    q.push({x+1,y});
                }
            }
            if(y+1<n)
            {
                if(ans[x][y+1]==-1)
                {
                    ans[x][y+1] = ans[x][y]+1;
                    q.push({x,y+1});
                }
            }
            if(x-1>=0)
            {
                if(ans[x-1][y]==-1)
                {
                    ans[x-1][y] = ans[x][y]+1;
                    q.push({x-1,y});
                }
            }
            if(y-1>=0)
            {
                if(ans[x][y-1]==-1)
                {
                    ans[x][y-1] = ans[x][y]+1;
                    q.push({x,y-1});
                }
            }
        }
        return ans;
    }
};
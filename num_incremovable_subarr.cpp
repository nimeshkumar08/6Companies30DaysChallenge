class Solution {
private:
    bool helper(vector<int>& nums, int len, int r)
    {
        int n=nums.size();
        int pre=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if((len<=i) && (i<=r)) continue;
            if(pre>=nums[i]) return false;
            pre=nums[i];
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int len=0;len<n;len++)
        {
            for(int r=len;r<n;r++)
            {
                if(helper(nums,len,r)) ans++;
            }
        }
        return ans;
    }
};
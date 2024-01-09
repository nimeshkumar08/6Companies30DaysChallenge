class Solution {
public: 
    void helper(int n, int id, int k, vector<int> &nums, int count)
    {
        if(nums.size() == 1) return;
        if(id >= n) id = 0;
        if(count == k)
        {
            nums.erase(nums.begin()+id);
            helper(n-1, id, k, nums, 1);
        }
        else
        {
            helper(n, id+1, k, nums, count+1);
        }
    }
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i=0; i<n; i++)
        {
            nums.push_back(i+1);
        }
        helper(n, 0, k, nums, 1);
        return nums[0];
    }
};
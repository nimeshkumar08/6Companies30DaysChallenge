class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[n/2]){
                ans+= nums[n/2]-nums[i];
                
            }
            else if(nums[i] == nums[n/2]){

            }
            else{
                ans+= nums[i] - nums[n/2];
            }
        }
        return ans;       
    }
};
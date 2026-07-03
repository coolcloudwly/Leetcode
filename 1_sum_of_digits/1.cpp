class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int n=0;n<nums.size();n++){
            int b=target-nums[n];
            for (int m=n+1;m<nums.size();m++){
                if(nums[m]==b){
                    return {n,m};
                }
            }
        }
        return {};
    }
};
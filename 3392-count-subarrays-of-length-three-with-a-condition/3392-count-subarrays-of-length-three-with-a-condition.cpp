class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            double sum = nums[i] + nums[i + 2];
            double targetSum = double(nums[i + 1]) / double(2.0);
            if(sum == targetSum){
                count++;
            }
        }

        return count;
    }
};
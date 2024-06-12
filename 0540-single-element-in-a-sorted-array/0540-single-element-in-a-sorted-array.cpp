class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return nums.back();
        }

        for(int i = 0; i < nums.size(); i += 2){
            if(i == nums.size() - 1){
                return nums.back();
            }
            
            if(nums[i] != nums[i + 1]){
                return nums[i];
            }
        }
        return -1;
    }
};
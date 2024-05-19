class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int required = target - nums[i];
            if(hashMap[required] > 0 && hashMap[required] != i){
                int requiredIndex = hashMap[required];
                return {i, requiredIndex};
            }
        }
        return nums;
    }
};
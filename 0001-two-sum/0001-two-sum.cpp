class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            int remaining = target - nums[i];

            if(hashMap.count(remaining) == 1){
                return {i, hashMap[remaining]};
            }

            hashMap[nums[i]] = i;
        }

        return {-1, -1};
    }
};
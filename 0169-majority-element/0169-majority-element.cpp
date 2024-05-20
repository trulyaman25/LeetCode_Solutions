class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
            if(hashMap[nums[i]] > nums.size() / 2){
                return nums[i];
            }
        }
        return 0;
    }
};
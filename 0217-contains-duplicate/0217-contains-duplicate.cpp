class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
            if(hashMap[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};
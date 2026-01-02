class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int length = nums.size() / 2;
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
            if(hashMap[nums[i]] == length){
                return nums[i];
            }
        }

        return -1;
    }
};
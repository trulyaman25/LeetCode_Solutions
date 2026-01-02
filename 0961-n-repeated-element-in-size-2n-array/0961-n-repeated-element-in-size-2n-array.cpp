class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        vector<int> hashArray(max + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            hashArray[nums[i]]++;
            if(hashArray[nums[i]] == nums.size() / 2){
                return nums[i];
            }
        }

        return -1;
    }
};
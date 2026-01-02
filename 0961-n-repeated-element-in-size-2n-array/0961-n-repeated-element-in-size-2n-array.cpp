class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        vector<int> hashArray(max + 1, 0);
        for(int i = 1; i <= nums.size(); i++){
            hashArray[nums[i - 1]]++;
            if(hashArray[nums[i - 1]] == nums.size() / 2){
                return nums[i - 1];
            }
        }

        return -1;
    }
};
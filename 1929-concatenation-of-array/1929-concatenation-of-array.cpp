class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int pointerOne = 0;
        int pointerTwo = nums.size();

        vector<int> ans(nums.size() * 2, 0);
        for(int i = 0; i < nums.size(); i++){
            ans[pointerOne++] = nums[i];
            ans[pointerTwo++] = nums[i];
        }

        return ans;
    }
};
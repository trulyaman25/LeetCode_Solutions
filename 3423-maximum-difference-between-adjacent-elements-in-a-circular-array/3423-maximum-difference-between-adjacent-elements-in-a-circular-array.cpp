class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDifference = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            int nextIndex = (i + 1) % nums.size();
            int difference = abs(nums[i] - nums[nextIndex]);

            maxDifference = max(difference, maxDifference);
        }

        return maxDifference;
    }
};
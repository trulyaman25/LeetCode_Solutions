class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ascendingLongest = 1;
        int descendingLongest = 1;

        int ascendingCount = 1;
        int descendingCount = 1;

        if (nums.size() == 1) {
            return 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                ascendingCount++;
                descendingCount = 1;
            } else if (nums[i] < nums[i - 1]) {
                descendingCount++;
                ascendingCount = 1;
            } else {
                ascendingCount = 1;
                descendingCount = 1;
            }

            ascendingLongest = max(ascendingLongest, ascendingCount);
            descendingLongest = max(descendingLongest, descendingCount);
        }

        return max(ascendingLongest, descendingLongest);
    }
};
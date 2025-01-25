class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque;
        deque<int> minDeque;

        int longestSubArray = 0;
        int pointerOne = 0;
        int pointerTwo = 0;

        while (pointerTwo < nums.size()) {
            while (!maxDeque.empty() && maxDeque.back() < nums[pointerTwo]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[pointerTwo]);

            while (!minDeque.empty() && minDeque.back() > nums[pointerTwo]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[pointerTwo]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[pointerOne] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (nums[pointerOne] == minDeque.front()) {
                    minDeque.pop_front();
                }
                pointerOne++;
            }

            longestSubArray = max(longestSubArray, pointerTwo - pointerOne + 1);
            
            pointerTwo++;
        }

        return longestSubArray;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int pointerOne = 0;
        int pointerTwo = 0;

        vector<int> resultantVector;
        deque<int> deque;
        while (pointerTwo < k) {
            while (!deque.empty() && nums[pointerTwo] >= nums[deque.back()]) {
                deque.pop_back();
            }
            
            deque.push_back(pointerTwo);
            pointerTwo++;
        }

        resultantVector.push_back(nums[deque.front()]);

        while (pointerTwo < nums.size()) {
            while (!deque.empty() && deque.front() <= pointerOne) {
                deque.pop_front();
            }

            while (!deque.empty() && nums[deque.back()] <= nums[pointerTwo]) {
                deque.pop_back();
            }

            deque.push_back(pointerTwo);

            resultantVector.push_back(nums[deque.front()]);

            pointerOne++;
            pointerTwo++;
        }

        return resultantVector;
    }
};

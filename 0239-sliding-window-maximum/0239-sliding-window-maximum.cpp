class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int pointerOne = 0;
        int pointerTwo = 0;
        
        vector<int> resultantVector;
        deque<int> deque;
        while (pointerTwo < k) {
            while (!deque.empty() && nums[pointerTwo] >= deque.back()) {
                deque.pop_back();
            }
            deque.push_back(nums[pointerTwo]);
            pointerTwo++;
        }

        resultantVector.push_back(deque.front());

        while (pointerTwo < nums.size()) {
            if (deque.front() == nums[pointerOne]) {
                deque.pop_front();
            }

            while (!deque.empty() && nums[pointerTwo] >= deque.back()) {
                deque.pop_back();
            }

            deque.push_back(nums[pointerTwo]);

            resultantVector.push_back(deque.front());

            pointerOne++;
            pointerTwo++;
        }

        return resultantVector;
    }
};
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> resultantVector;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = max(0, i - k); j <= min((int)nums.size() - 1, i + k); j++) {
                if (nums[j] == key) {
                    resultantVector.push_back(i);
                    break;
                }
            }
        }

        return resultantVector;
    }
};

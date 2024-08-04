class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vectorSum;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                vectorSum.push_back(sum);
            }
        }

        sort(vectorSum.begin(), vectorSum.end());

        for(int i = 0; i < vectorSum.size(); i++){
            cout << vectorSum[i] << " ";
        }

        return 0;
    }
};
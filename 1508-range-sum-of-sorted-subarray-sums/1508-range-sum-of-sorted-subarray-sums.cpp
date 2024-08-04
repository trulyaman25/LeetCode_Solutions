class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int> vectorSum;
        for(long long int i = 0; i < nums.size(); i++){
            long long int sum = 0;
            for(long long int j = i; j < nums.size(); j++){
                sum += nums[j];
                vectorSum.push_back(sum);
            }
        }

        sort(vectorSum.begin(), vectorSum.end());

        long long int resultantSum = 0;
        int mod = 1e9 + 7;
        for(long long int i = left - 1; i < right; i++){
            resultantSum = (resultantSum + vectorSum[i]) % mod;
        }

        return resultantSum;
    }
};
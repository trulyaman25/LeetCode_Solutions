class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int maxInt = nums[0];
        vector<long long> conversionArray;
        for(long long i = 0; i < nums.size(); i++){
            maxInt = max(maxInt, nums[i]);
            int value = nums[i] + maxInt;

            conversionArray.push_back(value);
        }

        vector<long long> prefixSum = {conversionArray[0]};

        for(long long i = 1; i < conversionArray.size(); i++){
            long long sum = prefixSum.back() + conversionArray[i];
            prefixSum.push_back(sum);
        }

        return prefixSum;
    }
};
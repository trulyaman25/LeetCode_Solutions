class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxValue = 0;
        for(long long i = 0; i < nums.size(); i++){
            for(long long j = i + 1; j < nums.size(); j++){
                for(long long k = j + 1; k < nums.size(); k++){
                    long long currentSum = ((long long)nums[i] - (long long)nums[j]) * (long long)nums[k];
                    maxValue = max(currentSum, maxValue);
                }
            }
        }
        return maxValue;
    }
};
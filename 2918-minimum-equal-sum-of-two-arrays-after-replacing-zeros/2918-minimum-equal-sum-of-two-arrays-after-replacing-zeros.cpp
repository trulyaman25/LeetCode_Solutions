class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sumOne = 0;
        long long zeroCountOne = 0;
        for(int i = 0; i < nums1.size(); i++){
            sumOne += nums1[i];
            if(nums1[i] == 0) zeroCountOne++;
        }

        long long sumTwo = 0;
        long long zeroCountTwo = 0;
        for(int i = 0; i < nums2.size(); i++){
            sumTwo += nums2[i];
            if(nums2[i] == 0) zeroCountTwo++;
        }

        long long minSumOne = sumOne + zeroCountOne;
        long long minSumTwo = sumTwo + zeroCountTwo;

        if(zeroCountOne > 0 && zeroCountTwo > 0){
            return max(minSumOne, minSumTwo);
        }

        if(zeroCountOne == 0 && minSumOne < minSumTwo){
            return -1;
        }

        if(zeroCountTwo == 0 && minSumTwo < minSumOne){
            return -1;
        }

        return max(minSumOne, minSumTwo);
    }
};

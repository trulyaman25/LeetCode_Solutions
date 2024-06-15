class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int leftPointer = 0;
        int rightPointer = 0;

        int zeroCount = 0;
        int maxLength = INT_MIN;
        for(int rightPointer = 0; rightPointer < nums.size(); rightPointer++){
            if(nums[rightPointer] == 0){
                zeroCount++;
            }

            if(zeroCount <= k){
                int length = rightPointer - leftPointer + 1;
                maxLength = max(maxLength, length);
            } else {
                while(zeroCount > k){
                    if(nums[leftPointer++] == 0){
                        zeroCount--;
                    }
                }
            }
        }

        return maxLength;
    }
};
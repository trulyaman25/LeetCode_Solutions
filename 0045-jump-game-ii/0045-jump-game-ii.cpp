class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpCount = 0;
        int leftPointer = 0;
        int rightPointer = 0;

        while(rightPointer < nums.size() - 1){
            int newRightIndex = 0;
            for(int i = leftPointer; i <= rightPointer; i++){
                int nextIndex = i + nums[i];
                newRightIndex = max(nextIndex, newRightIndex);
            }
            leftPointer = rightPointer + 1;
            rightPointer = newRightIndex;

            jumpCount++;
        }

        return jumpCount;
    }
};
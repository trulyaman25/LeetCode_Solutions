class Solution {
public:
    int longestOnes(vector<int>& nums, int threshold) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int longestSubString = 0;
        while(pointerTwo < nums.size()){
            if(nums[pointerTwo] == 0){
                threshold--;
            }

            while(threshold < 0){
                if(nums[pointerOne] == 0){
                    threshold++;
                }
                pointerOne++;
            }

            longestSubString = max(longestSubString, pointerTwo - pointerOne + 1);
            pointerTwo++;
        }

        return longestSubString;
    }
};
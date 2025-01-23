class Solution {
public:
    int longestOnes(vector<int>& nums, int life) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int maxLength = 0;
        while(pointerTwo < nums.size()){
            if(nums[pointerTwo] == 0){
                life--;
            }

            while(life < 0){
                if(nums[pointerOne] == 0){
                    life++;
                }
                pointerOne++;
            }

            maxLength = max(pointerTwo - pointerOne + 1, maxLength);
            pointerTwo++;
        }

        return maxLength;
    }
};
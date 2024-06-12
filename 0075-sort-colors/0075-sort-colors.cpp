class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeroCount++;
            } else if(nums[i] == 1){
                oneCount++;
            } else {
                twoCount++;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(zeroCount){
                nums[i] = 0;
                zeroCount--;
            } else if(oneCount){
                nums[i] = 1;
                oneCount--;
            } else if(twoCount) {
                nums[i] = 2;
                twoCount--;
            }
        }
    }
};
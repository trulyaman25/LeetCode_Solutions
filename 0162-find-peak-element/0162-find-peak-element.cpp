class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak = -1;

        if(nums.size() == 1){
            return 0;
        }

        int previous = INT_MIN;
        int next = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0){
                previous = nums[i - 1];
            } else {
                previous = INT_MIN;
            }

            if(i < nums.size() - 1){
                next = nums[i + 1];
            } else {
                next = INT_MIN;
            }

            if(previous < nums[i] && nums[i] > next){
                return i;
            }
        }

        return peak;
    }
};
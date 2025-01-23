class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1){
            return 0;
        }
        
        int product = 1;
        int count = 0;

        int pointerOne = 0;
        int pointerTwo = 0;
        while (pointerTwo < nums.size()) {
            product *= nums[pointerTwo];

            while (product >= k && pointerOne <= pointerTwo) {
                product /= nums[pointerOne];
                pointerOne++;
            }

            count += (pointerTwo - pointerOne + 1);
            pointerTwo++;
        }

        return count;
    }
};

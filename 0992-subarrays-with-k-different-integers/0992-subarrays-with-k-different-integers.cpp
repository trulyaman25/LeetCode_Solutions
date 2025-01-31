class Solution {
public:
    int countSubArray(vector<int>& nums, int k){
        int pointerOne = 0;
        int pointerTwo = 0;

        int subArrayCount = 0;
        
        unordered_map<int, int> frequency;
        while(pointerTwo < nums.size()){
            if(frequency[nums[pointerTwo]] == 0){
                k--;
            }

            frequency[nums[pointerTwo]]++;

            while(k < 0){
                frequency[nums[pointerOne]]--;
                if(frequency[nums[pointerOne]] == 0){
                    frequency.erase(nums[pointerOne]);
                    k++;
                }
                pointerOne++;
            }
            
            subArrayCount += pointerTwo - pointerOne + 1;
            pointerTwo++;
        }

        return subArrayCount;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubArray(nums, k) - countSubArray(nums, k - 1);
    }
};
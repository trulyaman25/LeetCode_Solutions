class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int windowSize = k;
        for(int i = 0; i < windowSize - 1; i++){
            nums.push_back(nums[i]);
        }

        int groupCount = 0;
        
        int pointerOne = 0;
        int pointerTwo = 1;
        while(pointerTwo < nums.size()){
            if(nums[pointerTwo] == nums[pointerTwo - 1]){
                pointerOne = pointerTwo;
            }

            if(pointerTwo - pointerOne + 1 < windowSize){
                pointerTwo++;
            } else {
                groupCount++;

                pointerOne++;
                pointerTwo++;
            }
        }

        return groupCount;
    }
};
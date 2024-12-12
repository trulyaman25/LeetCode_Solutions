class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        int targetCount = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                targetCount++;
            }
        }

        bool startFound = false;
        for(int i = 0; i < nums.size(); i++){
            if(!startFound){
                if(nums[i] == target){
                    start = i;
                    startFound = true;
                }
            }

            if(nums[i] == target && i != start || nums[i] == target && targetCount == 1){
                end = i;
            }
        }

        vector<int> result;
        result.push_back(start);
        result.push_back(end);

        return result;
    }
};
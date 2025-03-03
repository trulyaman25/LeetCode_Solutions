class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> resultantVector;
        int pivotCount = 0;
        vector<int> leftHalf;
        vector<int> rightHalf;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                leftHalf.push_back(nums[i]);
            } else if (nums[i] > pivot){
                rightHalf.push_back(nums[i]);
            } else {
                pivotCount++;
            }
        }

        int index = 0;
        while(index < leftHalf.size()){
            resultantVector.push_back(leftHalf[index]);
            index++;
        }

        index = 0;
        while(pivotCount--){
            resultantVector.push_back(pivot);
        }

        index = 0;
        while(index < rightHalf.size()){
            resultantVector.push_back(rightHalf[index]);
            index++;
        }

        return resultantVector;
    }
};
class Solution {
public:
    void merge(vector<int>& assetVector, int low, int mid, int high){
        vector<int> tempVector;

        int leftPointer = low;
        int rightPointer = mid + 1;

        while(leftPointer <= mid && rightPointer <= high){
            if(assetVector[leftPointer] <= assetVector[rightPointer]){
                tempVector.push_back(assetVector[leftPointer++]);
            } else {
                tempVector.push_back(assetVector[rightPointer++]);
            }
        }

        while(leftPointer <= mid){
            tempVector.push_back(assetVector[leftPointer++]);
        }

        while(rightPointer <= high){
            tempVector.push_back(assetVector[rightPointer++]);
        }

        for(int i = low; i <= high; i++){
            assetVector[i] = tempVector[i - low];
        }
    }

    void mergeSort(vector<int>& assetVector, int low, int high){
        if(low == high){
            return;
        }

        int mid = (low + high) / 2;
        mergeSort(assetVector, low, mid);
        mergeSort(assetVector, mid + 1, high);
        merge(assetVector, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
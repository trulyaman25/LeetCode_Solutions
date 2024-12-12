class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int pointerOne = 0;
        int pointerTwo = arr.size() - 1;
        while(pointerOne <= pointerTwo){
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int value = arr[mid];

            if(value > arr[mid - 1] && value > arr[mid + 1]){
                return mid;
            } else if (value > arr[mid - 1] && value < arr[mid + 1]){
                pointerOne = pointerOne + 1;
            } else if (value < arr[mid - 1] && value > arr[mid + 1]) {
                pointerTwo = pointerTwo - 1;
            }
        }

        return -1;
    }
};
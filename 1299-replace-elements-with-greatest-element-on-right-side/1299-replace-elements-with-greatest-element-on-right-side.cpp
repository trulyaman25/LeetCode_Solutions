class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxElement = -1;
        for(int i = arr.size() - 1; i >= 0; i--){
            int refferenceValue = arr[i];
            arr[i] = maxElement;
            if(refferenceValue > maxElement){
                maxElement = refferenceValue;
            }
        }

        return arr;
    }
};
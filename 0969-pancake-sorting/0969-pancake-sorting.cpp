class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> resultantVector;
        int unsortedNumber = arr.size();
        while(unsortedNumber > 0){
            auto it = find(arr.begin(), arr.end(), unsortedNumber);
            int index = distance(arr.begin(), it);
            reverse(arr.begin(), arr.begin() + index + 1);
            resultantVector.push_back(index + 1);
            reverse(arr.begin(), arr.begin() + arr.size() - (arr.size() - unsortedNumber));
            resultantVector.push_back(arr.size() - (arr.size() - unsortedNumber));
            unsortedNumber--;
        }

        return resultantVector;
    }
};
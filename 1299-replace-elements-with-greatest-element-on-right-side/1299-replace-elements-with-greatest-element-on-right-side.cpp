//BRUTE FORCE SOLUTION
// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         for(int i = 0; i < arr.size(); i++){
//             int maxElement = INT_MIN;
//             for(int j = i + 1; j < arr.size(); j++){
//                 if(arr[j] > maxElement){
//                     maxElement = arr[j];
//                 }
//             }
//             arr[i] = maxElement;
//         }
//         arr.back() = -1;

//         return arr;
//     }
// };

//OPTIMIZED SOLUTION
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
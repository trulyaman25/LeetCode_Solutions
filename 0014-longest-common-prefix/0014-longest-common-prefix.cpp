//BRUTEFORCE SOLUTION
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string resultantString = "";

//         if(strs.size() == 1){
//             return strs[0];
//         }

//         if(strs.size() > 1){
//             sort(strs.begin(), strs.end());
//             string initialWord = strs[0];

//             for(int i = strs.size() - 1; i >= 1; i--){
//                 string comparisionWord = strs[i];
//                 int limitingLength = min(initialWord.length(), comparisionWord.length());

//                 for(int j = 0; j < limitingLength; j++){
//                     if(initialWord[j] == comparisionWord[j]){
//                         resultantString += initialWord[j];
//                     } else {
//                         return resultantString;
//                     }
//                 }

//                 if(resultantString == initialWord){
//                     return resultantString;
//                 }
//             }
//         }
 
//         return resultantString;
//     }
// };

//BETTER SOLUTION
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string resultantString = "";
        string refferenceString = strs[0];
        
        for(int i = 0; i < refferenceString.length(); i++){
            for(int j = 0; j < strs.size(); j++){
                if(refferenceString[i] != strs[j][i]){
                    return resultantString;
                }
            }
            resultantString += refferenceString[i];
        }

        return resultantString;
    }
};
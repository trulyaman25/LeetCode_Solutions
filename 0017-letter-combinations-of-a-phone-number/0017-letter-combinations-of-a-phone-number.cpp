class Solution {
public:
    void findCombinations(string& assetString, unordered_map<char, string>& hashMap, vector<string>& resultantVector, string tempString, int index){
        if(index >= assetString.length()){
            resultantVector.push_back(tempString);
            return;
        }

        string possibleChar = hashMap[assetString[index]];

        for(int i = 0; i < possibleChar.length(); i++){
            tempString += possibleChar[i];
            findCombinations(assetString, hashMap, resultantVector, tempString, index + 1);
            tempString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }

        unordered_map<char, string> hashMap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> resultantVector;
        findCombinations(digits, hashMap, resultantVector, "", 0);

        return resultantVector;
    }
};
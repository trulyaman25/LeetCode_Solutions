class Solution {
public:
    void backtrack(int index, string& assetString, string& dataString, vector<string>& resultantVector){
        if(index == assetString.length()){
            resultantVector.push_back(dataString);
            return;
        }

        dataString += assetString[index];
        backtrack(index + 1, assetString, dataString, resultantVector);
        dataString.pop_back();

        if (assetString[index] >= 97 && assetString[index] <= 122){
            dataString += toupper(assetString[index]);
            backtrack(index + 1, assetString, dataString, resultantVector);
            dataString.pop_back();
        }

        if (assetString[index] >= 65 && assetString[index] <= 90){
            dataString += tolower(assetString[index]);
            backtrack(index + 1, assetString, dataString, resultantVector);
            dataString.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        string dataString;
        vector<string> resultantVector;
        backtrack(0, s, dataString, resultantVector);

        return resultantVector;
    }
};
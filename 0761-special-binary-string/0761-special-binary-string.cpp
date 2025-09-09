class Solution {
public:
    string makeLargestSpecial(string S) {
        int count = 0;
        int i = 0;
        vector<string> assetVector;
        for(int j = 0; j < S.size(); j++){
            if(S[j] == '1'){
                count++;
            } else {
                count--;
            }

            if(count == 0){
                assetVector.push_back("1" + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + "0");
                i = j + 1;
            }
        }

        sort(assetVector.begin(), assetVector.end(), greater<string>());

        string result = "";
        for(int i = 0; i < assetVector.size(); i++){
            result += assetVector[i];
        }

        return result;
    }
};
class Solution {
public:
    void findPermutations(int index, string dataString, set<string>& resultantVector){
        resultantVector.insert(dataString);
        for(int i = index; i < dataString.length(); i++){
            swap(dataString[index], dataString[i]);
            findPermutations(index + 1, dataString, resultantVector);
            swap(dataString[index], dataString[i]);
        }
    }

    void findCombination(int index, string& assetString, string& dataString, set<string>& resultantVector){
        resultantVector.insert(dataString);
        for(int i = index; i < assetString.length(); i++){
            if(i > index && assetString[i] == assetString[i - 1]){
                continue;
            }

            dataString += assetString[i];
            if(dataString.length() >= 2){
                findPermutations(0, dataString, resultantVector);
            }
            findCombination(i + 1, assetString, dataString, resultantVector);
            dataString.pop_back();
        }
    }

    int numTilePossibilities(string s) {
        sort(s.begin(), s.end());

        string tempString;
        set<string> resultantVector;
        findCombination(0, s, tempString, resultantVector);

        return resultantVector.size() - 1;
    }
};
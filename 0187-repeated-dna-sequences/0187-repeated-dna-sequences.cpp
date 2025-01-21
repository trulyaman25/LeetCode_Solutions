class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int pointerOne = 0;
        int pointerTwo = 0;

        vector<string> resultantVector;

        if(s.length() <= 10){
            return resultantVector;
        }

        unordered_map<string, int> stringMap;
        string currentString;
        while(pointerTwo < 10){
            currentString += s[pointerTwo];
            pointerTwo++;
        }

        stringMap[currentString]++;

        while(pointerTwo < s.length()){
            currentString += s[pointerTwo];
            currentString.erase(0, 1);

            stringMap[currentString]++;

            pointerOne++;
            pointerTwo++;
        }

        for(auto &it : stringMap){
            if(it.second > 1){
                resultantVector.push_back(it.first);
            }
        }

        return resultantVector;
    }
};
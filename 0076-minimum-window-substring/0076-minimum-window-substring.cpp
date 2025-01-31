class Solution {
public:
    string minWindow(string s, string t) {
        int pointerOne = 0;
        int pointerTwo = 0;
        
        unordered_map<char, int> patternMap;
        for(int i = 0; i < t.size(); i++){
            patternMap[t[i]]++;
        }

        string resultantString;

        int minLength = INT_MAX;
        int startIndex = 0;

        int charRequired = patternMap.size();
        while(pointerTwo < s.length()){
            if(patternMap.count(s[pointerTwo]) > 0){
                patternMap[s[pointerTwo]]--;
                if(patternMap[s[pointerTwo]] == 0){
                    charRequired--;
                }
            }

            while(charRequired == 0 && pointerOne <= pointerTwo){
                if(pointerTwo - pointerOne + 1 < minLength){
                    minLength = pointerTwo - pointerOne + 1;
                    startIndex = pointerOne;
                }

                if(patternMap.count(s[pointerOne])){
                    patternMap[s[pointerOne]]++;
                    if(patternMap[s[pointerOne]] > 0){
                        charRequired++;
                    }
                }
                pointerOne++;
            }

            pointerTwo++;
        }

        if(minLength == INT_MAX){
            return "";
        } else {
            resultantString = s.substr(startIndex, minLength);
        }

        return resultantString;
    }
};
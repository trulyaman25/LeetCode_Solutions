class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int pointerTwo = 0;
        int pointerOne = 0;

        if(s1.length() > s2.length()){
            return false;
        }

        unordered_map<char, int> patternMap;
        for(int i = 0; i < s1.length(); i++){
            patternMap[s1[i]]++;
        }

        int uniqueCount = patternMap.size();

        while(pointerTwo < s1.length()){
            if(patternMap.count(s2[pointerTwo])){
                patternMap[s2[pointerTwo]]--;
                if(patternMap[s2[pointerTwo]] == 0){
                    uniqueCount--;
                }
            }

            pointerTwo++;
        }

        if(uniqueCount == 0){
            return true;
        }

        while(pointerTwo < s2.length()){
            if(patternMap.count(s2[pointerTwo])){
                patternMap[s2[pointerTwo]]--;
                if(patternMap[s2[pointerTwo]] == 0){
                    uniqueCount--;
                }
            }

            if(patternMap.count(s2[pointerOne])){
                if(patternMap[s2[pointerOne]] == 0){
                    uniqueCount++;
                }
                patternMap[s2[pointerOne]]++;
            }

            if(uniqueCount == 0){
                return true;
            }

            pointerOne++;
            pointerTwo++;
        }

        return false;
    }
};
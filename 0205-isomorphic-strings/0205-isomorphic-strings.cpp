class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> patternMap, reverseMap;
        
        for(int i = 0; i < s.length(); i++) {
            if(patternMap.count(s[i]) == 0) {
                if(reverseMap.count(t[i]) == 0) {
                    patternMap[s[i]] = t[i];
                    reverseMap[t[i]] = s[i];
                } else {
                    return false;
                }
            } else {
                if(patternMap[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
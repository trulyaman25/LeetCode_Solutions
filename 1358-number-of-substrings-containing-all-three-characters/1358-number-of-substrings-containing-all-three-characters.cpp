class Solution {
public:
    int numberOfSubstrings(string s) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int substringCount = 0;
        unordered_map<char, int> hashMap;
        while(pointerTwo < s.length()){
            hashMap[s[pointerTwo]]++;
            while(hashMap.size() == 3){
                hashMap[s[pointerOne]]--;
                if(hashMap[s[pointerOne]] <= 0){
                    hashMap.erase(s[pointerOne]);
                }
                substringCount += s.length() - pointerTwo;
                pointerOne++;
            }
            pointerTwo++;
        }

        return substringCount;
    }
};
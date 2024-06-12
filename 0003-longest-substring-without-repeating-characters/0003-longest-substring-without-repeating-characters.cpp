class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int maxLength = 0;
        unordered_map<char, int> hashMap;
        while(pointerTwo < s.length()){
            hashMap[s[pointerTwo]]++;
            while(hashMap[s[pointerTwo]] > 1){
                if(hashMap[s[pointerOne]] > 0){
                    hashMap[s[pointerOne]]--;
                }
                pointerOne++;
            }

            maxLength = max(maxLength, pointerTwo - pointerOne + 1);
            pointerTwo++;
        }

        return maxLength;
    }
};
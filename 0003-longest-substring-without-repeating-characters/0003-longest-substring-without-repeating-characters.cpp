class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charFrequency;

        int pointerOne = 0;
        int pointerTwo = 0;

        int maxLength = 0;
        while(pointerTwo < s.length()){
            charFrequency[s[pointerTwo]]++;
            while(charFrequency[s[pointerTwo]] > 1){
                charFrequency[s[pointerOne]]--;
                if(charFrequency[s[pointerOne]] == 0){
                    charFrequency.erase(s[pointerOne]);
                }
                pointerOne++;
            }
            maxLength = max(maxLength, pointerTwo - pointerOne + 1);
            pointerTwo++;
        }

        return maxLength;
    }
};
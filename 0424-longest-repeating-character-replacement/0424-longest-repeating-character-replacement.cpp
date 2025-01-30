class Solution {
public:
    int characterReplacement(string s, int k) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int maxFrequency = 0;
        int longestSubString = 0;

        unordered_map<char, int> charFrequency;
        while(pointerTwo < s.length()){
            charFrequency[s[pointerTwo]]++;
            maxFrequency = max(maxFrequency, charFrequency[s[pointerTwo]]);

            while(pointerTwo - pointerOne + 1 - maxFrequency> k){
                charFrequency[s[pointerOne]]--;
                pointerOne++;
            }

            longestSubString = max(longestSubString, pointerTwo - pointerOne + 1);
            pointerTwo++;
        }

        return longestSubString;
    }
};
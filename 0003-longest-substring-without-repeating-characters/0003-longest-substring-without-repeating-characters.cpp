class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1){
            return s.length();
        }

        unordered_map<char, int> frequency;

        int maxLength = INT_MIN;
        int leftPointer = 0;
        int rightPointer = 0;
        while(rightPointer <= s.length()){
            int currentLength = rightPointer - leftPointer;
            maxLength = max(currentLength, maxLength);

            if(frequency[s[rightPointer]] == 0){
                frequency[s[rightPointer]]++;
                rightPointer++;
            } else {
                while(leftPointer <= rightPointer && frequency[s[rightPointer]] != 0){
                    frequency[s[leftPointer]]--;
                    leftPointer++;
                }
            }
        }

        return maxLength;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int lengthCount = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] != ' '){
                lengthCount++;
            }
            if(lengthCount > 0 && s[i] == ' '){
                return lengthCount;
            }
        }
        return lengthCount;
    }
};
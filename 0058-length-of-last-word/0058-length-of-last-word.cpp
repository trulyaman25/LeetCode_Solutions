class Solution {
public:
    int lengthOfLastWord(string s) {
        int lengthCount = 0;
        bool flag = false;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122){
                lengthCount++;
            }
            if(lengthCount > 0 && s[i] == ' '){
                return lengthCount;
            }
        }

        return lengthCount;
    }
};
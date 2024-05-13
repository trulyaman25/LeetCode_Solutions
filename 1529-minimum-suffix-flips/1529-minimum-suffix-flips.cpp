class Solution {
public:
    int minFlips(string target) {
        string s(target.length(), '0');

        int flipCount = 0;
        bool invertFlag = false;
        for(int i = 0; i < target.length(); i++){
            if(target[i] != s[i] && !invertFlag){
                invertFlag = true;
                flipCount++;
            } else if (target[i] == s[i] && invertFlag){
                invertFlag = false;
                flipCount++;
            }
        }

        return flipCount;
    }
};
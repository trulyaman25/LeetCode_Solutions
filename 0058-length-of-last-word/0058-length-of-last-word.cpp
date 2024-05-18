class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool flag = false;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ' '){
                if(!flag){
                    continue;
                } else {
                    break;
                }
            } else {
                count++;
                flag = true;
            }
        }

        return count;
    }
};
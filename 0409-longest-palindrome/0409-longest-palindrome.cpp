class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 1){
            return 1;
        }

        unordered_map<char, int> hashMap;
        for (int i = 0; i < s.length(); i++) {
            hashMap[s[i]]++;

            if(hashMap[s[i]] == s.length()){
                return s.length();
            }
        }

        int length = 0;
        bool flag = false;
        for (auto it : hashMap) {
            if (it.second % 2 != 0 && flag){
                continue;
            }
            
            if (it.second % 2 != 0 && !flag) {
                if(it.second == 1){
                    length++;
                } else {
                    length += it.second - 1;
                }
                flag = true;
            } else {
                length += it.second;
            }
        }

        return length;
    }
};
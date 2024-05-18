class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[27] = {0};
        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a']++;
        }

        for(int i = 0; i < t.length(); i++){
            hash[t[i] - 'a']--;
        }

        for(int i = 0; i < 27; i++){
            if(hash[i] != 0){
                return false;
            }
        }

        return true;
    }
};
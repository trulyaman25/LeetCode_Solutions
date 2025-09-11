class Solution {
public:
    bool isVovel(char s){
        if(s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U' || s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'){
            return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> sorted;
        for(int i = 0; i < s.length(); i++){
            if(isVovel(s[i])){
                sorted.push_back(s[i]);
            }
        }

        sort(sorted.rbegin(), sorted.rend());

        for(int i = 0; i < s.length(); i++){
            if(isVovel(s[i])){
                s[i] = sorted.back();
                sorted.pop_back();
            }
        }

        return s;
    }
};
class Solution {
public:
    int appendCharacters(string s, string t) {
        int pointerOne = 0;
        int pointerTwo = 0;
        while(pointerOne < s.length() && pointerTwo < t.length()){
            if(s[pointerOne] == t[pointerTwo]){
                pointerOne++;
                pointerTwo++;
            } else if(s[pointerOne] != t[pointerTwo]){
                pointerOne++;
            }
        }
        return t.length() - pointerTwo;
    }
};
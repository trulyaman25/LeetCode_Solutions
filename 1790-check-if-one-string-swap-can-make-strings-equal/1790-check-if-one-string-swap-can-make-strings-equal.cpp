class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int pointerOne = 0;
        int pointerTwo = 0;
        int count = 0;
        unordered_map<char, int> mapOne;
        unordered_map<char, int> mapTwo;
        
        while(pointerTwo < s1.length()){
            if(s1[pointerOne] != s2[pointerTwo]){
                count++;
            }
            if(count > 2){
                return false;
            }

            mapOne[s1[pointerOne]]++;
            mapTwo[s2[pointerTwo]]++;

            pointerOne++;
            pointerTwo++;
        }

        if(count >= 1 && mapOne != mapTwo){
            return false;
        }

        return true;
    }
};
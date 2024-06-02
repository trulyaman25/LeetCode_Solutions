class Solution {
public:
    void reverseString(vector<char>& s) {
        int pointerOne = 0;
        int pointerTwo = s.size() - 1;
        while(pointerOne < pointerTwo){
            char tempStorage = s[pointerOne];
            s[pointerOne] = s[pointerTwo];
            s[pointerTwo] = tempStorage;
            pointerOne++;
            pointerTwo--;
        }
    }
};
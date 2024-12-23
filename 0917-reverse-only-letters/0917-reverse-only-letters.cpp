class Solution {
public:
    string reverseOnlyLetters(string s) {
        int pointerOne = 0;
        int pointerTwo = s.length() - 1;

        while (pointerOne < pointerTwo) {
            while (pointerOne < pointerTwo && !isalpha(s[pointerOne])) {
                pointerOne++;
            }

            while (pointerOne < pointerTwo && !isalpha(s[pointerTwo])) {
                pointerTwo--;
            }
            
            swap(s[pointerOne], s[pointerTwo]);
            pointerOne++;
            pointerTwo--;
        }

        return s;
    }
};
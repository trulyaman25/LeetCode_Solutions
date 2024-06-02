class Solution {
public:
    void reverseString(vector<char>& s) {
        int pointerOne = 0;
        int pointerTwo = s.size() - 1;
        while(pointerOne < pointerTwo){
            swap(s[pointerOne++], s[pointerTwo--]);
        }
    }
};
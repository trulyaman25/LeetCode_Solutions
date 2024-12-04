class Solution {
public:
    bool canMakeSubsequence(string stringOne, string stringTwo) {
        int pointerOne = 0;
        int pointerTwo = 0;

        if(stringOne.length() < stringTwo.length()){
            return false;
        }

        while(pointerOne < stringOne.length() && pointerTwo < stringTwo.length()){
            if(stringOne[pointerOne] == stringTwo[pointerTwo]){
                pointerOne++;
                pointerTwo++;
            } else if (stringOne[pointerOne] == 'z' && stringTwo[pointerTwo] == 'a'){
                pointerOne++;
                pointerTwo++;
            } else if (stringOne[pointerOne] + 1 == stringTwo[pointerTwo]){
                pointerOne++;
                pointerTwo++;
            } else {
                pointerOne++;
            }
        }

        if(pointerTwo == stringTwo.length()){
            return true;
        }

        return false;
    }
};
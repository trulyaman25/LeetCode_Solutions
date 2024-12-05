class Solution {
public:
    bool canChange(string assetString, string targetString) {
        int pointerOne = 0;
        int pointerTwo = 0;

        while (pointerOne < assetString.length() && pointerTwo < targetString.length()) {
            while (assetString[pointerOne] == '_') {
                pointerOne++;
            }
            while (targetString[pointerTwo] == '_') {
                pointerTwo++;
            }

            if (pointerOne == assetString.length() && pointerTwo == targetString.length()) {
                return true;
            } else if (pointerOne == assetString.length() || pointerTwo == targetString.length()) {
                return false;
            } else if (assetString[pointerOne] != targetString[pointerTwo]) {
                return false;
            } else if (assetString[pointerOne] == 'L' && pointerTwo > pointerOne) {
                return false;
            } else if (assetString[pointerOne] == 'R' && pointerTwo < pointerOne) {
                return false;
            }

            pointerOne++;
            pointerTwo++;
        }

        return true;
    }
};

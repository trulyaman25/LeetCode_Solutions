class Solution {
public:
    void generate(int validPairs, int openCount, int closeCount, string tempString, vector<string>& resultantVector) {
        if (tempString.length() == validPairs * 2) {
            resultantVector.push_back(tempString);
            return;
        }

        if (openCount < validPairs) {
            tempString += '(';
            generate(validPairs, openCount + 1, closeCount, tempString, resultantVector);
            tempString.pop_back();
        }

        if (closeCount < openCount) {
            tempString += ')';
            generate(validPairs, openCount, closeCount + 1, tempString, resultantVector);
            tempString.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> resultantVector;
        generate(n, 0, 0, "", resultantVector);
        
        return resultantVector;
    }
};
class Solution {
public:
    int getLCSS(string& stringOne, string& stringTwo, int indexOne, int indexTwo, vector<vector<int>>& dp){
        if(indexOne < 0 || indexTwo < 0){
            return 0;
        }

        if(dp[indexOne][indexTwo] != -1){
            return dp[indexOne][indexTwo];
        }

        if(stringOne[indexOne] == stringTwo[indexTwo]){
            return 1 + getLCSS(stringOne, stringTwo, indexOne - 1, indexTwo - 1, dp);
        }

        int caseOne = getLCSS(stringOne, stringTwo, indexOne - 1, indexTwo, dp);
        int caseTwo = getLCSS(stringOne, stringTwo, indexOne, indexTwo - 1, dp);

        return dp[indexOne][indexTwo] = max(caseOne, caseTwo);
    }

    int minInsertions(string s) {
        string reversedString = s;
        reverse(reversedString.begin(), reversedString.end());

        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));

        return s.length() - getLCSS(s, reversedString, s.length() - 1, s.length() - 1, dp);
    }
};
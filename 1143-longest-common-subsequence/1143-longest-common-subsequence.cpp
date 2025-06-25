class Solution {
public:
    int getLCSS(string& stringOne, string& stringTwo, int indexOne, int indexTwo, vector<vector<int>>& dp){
        if(indexOne >= stringOne.length()){
            return 0;
        }

        if(indexTwo >= stringTwo.length()){
            return 0;
        }

        if(dp[indexOne][indexTwo] != -1){
            return dp[indexOne][indexTwo];
        }

        if(stringOne[indexOne] == stringTwo[indexTwo]){
            return getLCSS(stringOne, stringTwo, indexOne + 1, indexTwo + 1, dp) + 1;
        }

        int caseOne = getLCSS(stringOne, stringTwo, indexOne + 1, indexTwo, dp);
        int caseTwo = getLCSS(stringOne, stringTwo, indexOne, indexTwo + 1, dp);

        return dp[indexOne][indexTwo] = max(caseOne, caseTwo);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return getLCSS(text1, text2, 0, 0, dp);
    }
};
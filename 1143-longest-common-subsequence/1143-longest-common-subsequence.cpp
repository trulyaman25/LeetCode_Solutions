class Solution {
public:
    int getLCSS(string& textOne, string& textTwo, int indexOne, int indexTwo, vector<vector<int>>& dp){
        if(indexOne < 0 || indexTwo < 0){
            return 0;
        }

        if(dp[indexOne][indexTwo] != -1){
            return dp[indexOne][indexTwo];
        }

        if(textOne[indexOne] == textTwo[indexTwo]){
            return getLCSS(textOne, textTwo, indexOne - 1, indexTwo - 1, dp) + 1;
        }

        int caseOne = getLCSS(textOne, textTwo, indexOne - 1, indexTwo, dp);
        int caseTwo = getLCSS(textOne, textTwo, indexOne, indexTwo - 1, dp);

        return dp[indexOne][indexTwo] = max(caseOne, caseTwo);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return getLCSS(text1, text2, text1.length() - 1, text2.length() - 1, dp);
    }
};
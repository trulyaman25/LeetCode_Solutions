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

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return word1.length() + word2.length() - 2 * getLCSS(word1, word2, word1.length() - 1, word2.length(), dp);
    }
};
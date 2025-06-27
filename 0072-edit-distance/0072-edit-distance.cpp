class Solution {
public:
    int getDist(string& stringOne, string& stringTwo, int indexOne, int indexTwo, vector<vector<int>>& dp){
        if(indexOne < 0){
            return indexTwo + 1;
        }

        if(indexTwo < 0){
            return indexOne + 1;
        }

        if(dp[indexOne][indexTwo] != -1){
            return dp[indexOne][indexTwo];
        }

        if(stringOne[indexOne] == stringTwo[indexTwo]){
            return dp[indexOne][indexTwo] = getDist(stringOne, stringTwo, indexOne - 1, indexTwo - 1, dp);
        }

        return dp[indexOne][indexTwo] = 1 + min({
            getDist(stringOne, stringTwo, indexOne, indexTwo - 1, dp),
            getDist(stringOne, stringTwo, indexOne - 1, indexTwo, dp),
            getDist(stringOne, stringTwo, indexOne - 1, indexTwo - 1, dp)
        });
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return getDist(word1, word2, word1.length() - 1, word2.length() - 1, dp);
    }
};
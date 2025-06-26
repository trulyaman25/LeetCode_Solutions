class Solution {
public:
    int getDSS(string& stringOne, string& stringTwo, int indexOne, int indexTwo, vector<vector<int>>& dp){
        if(indexTwo < 0){
            return 1;
        }

        if(indexOne < 0){
            return 0;
        }

        if(dp[indexOne][indexTwo] != -1){
            return dp[indexOne][indexTwo];
        }

        if(stringOne[indexOne] == stringTwo[indexTwo]){
            return dp[indexOne][indexTwo] = getDSS(stringOne, stringTwo, indexOne - 1, indexTwo - 1, dp) + getDSS(stringOne, stringTwo, indexOne - 1, indexTwo, dp);
        }

        return dp[indexOne][indexTwo] = getDSS(stringOne, stringTwo, indexOne - 1, indexTwo, dp);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return getDSS(s, t, s.length() - 1, t.length() - 1, dp);
    }
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));

        //setting up the baseCase
        for(int i = 0; i <= text1.length(); i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= text2.length(); j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= text1.length(); i++){
            for(int j = 1; j <= text2.length(); j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    int caseOne = dp[i - 1][j];
                    int caseTwo = dp[i][j - 1];

                    dp[i][j] = max(caseOne, caseTwo);
                }
            }
        }


        return dp.back().back();
    }
};
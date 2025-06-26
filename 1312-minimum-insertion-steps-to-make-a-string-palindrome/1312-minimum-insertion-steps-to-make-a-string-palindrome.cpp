class Solution {
public:
    int minInsertions(string s) {
        string reversedString = s;
        reverse(reversedString.begin(), reversedString.end());

        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));

        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                if(s[i - 1] == reversedString[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    int caseOne = dp[i - 1][j];
                    int caseTwo = dp[i][j - 1];

                    dp[i][j] = max(caseOne, caseTwo);
                }
            }
        }

        return s.length() - dp.back().back();
    }
};
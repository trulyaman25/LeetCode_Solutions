class Solution {
public:
    int getLCSS(string& stringOne, string& stringTwo, int indexOne, int indexTwo, vector<vector<int>>& dp){
        if(indexOne <= 0 || indexTwo <= 0){
            return 0;
        }

        if(dp[indexOne][indexTwo] != -1){
            return dp[indexOne][indexTwo];
        }

        if(stringOne[indexOne - 1] == stringTwo[indexTwo - 1]){
            return dp[indexOne][indexTwo] = 1 + getLCSS(stringOne, stringTwo, indexOne - 1, indexTwo - 1, dp);
        }

        int caseOne = getLCSS(stringOne, stringTwo, indexOne - 1, indexTwo, dp);
        int caseTwo = getLCSS(stringOne, stringTwo, indexOne, indexTwo - 1, dp);

        return dp[indexOne][indexTwo] = max(caseOne, caseTwo);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, -1));
        int length = str1.length() + str2.length() - getLCSS(str1, str2, str1.length(), str2.length(), dp);

        string resultantString = "";

        int i = str1.length();
        int j = str2.length();
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                resultantString += str1[i - 1];
                i--;
                j--; 
            } else if(dp[i - 1][j] > dp[i][j - 1]){
                resultantString += str1[i - 1];
                i--;
            } else {
                resultantString += str2[j - 1];
                j--;
            }
        }

        while(i > 0){
            resultantString += str1[i - 1];
            i--;
        }

        while(j > 0){
            resultantString += str2[j - 1];
            j--;
        }

        reverse(resultantString.begin(), resultantString.end());
        return resultantString;
    }
};
class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;
        int consecutiveCount = 0;

        for(int i = 1; i < word.size(); i++){
            if(word[i - 1] == word[i]){
                consecutiveCount++;
            } else {
                count += consecutiveCount;
                consecutiveCount = 0;
            }
        }
        
        count += consecutiveCount;

        return count + 1;
    }
};
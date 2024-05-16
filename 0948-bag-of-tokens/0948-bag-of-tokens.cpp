class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int pointerOne = 0;
        int pointerTwo = tokens.size() - 1;
        int score = 0;
        int maxScore= 0;
        
        sort(tokens.begin(), tokens.end());
        while(pointerOne <= pointerTwo){
            if(tokens[pointerOne] <= power){
                power -= tokens[pointerOne++];
                score++;
            } else if(score >= 1) {
                power += tokens[pointerTwo--];
                score--;
            } else {
                break;
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
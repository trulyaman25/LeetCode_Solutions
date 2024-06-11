class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftScore = 0;
        int rightScore = 0;
        int pointer = cardPoints.size() - 1;

        for(int i = 0; i < k; i++){
            leftScore += cardPoints[i];
        }

        int maxScore = leftScore;
        for(int i = 0; i < k; i++){
            rightScore += cardPoints[pointer - i];
            leftScore -= cardPoints[k - 1 - i];
            maxScore = max(maxScore, leftScore + rightScore);
        }

        return maxScore;
    }
};
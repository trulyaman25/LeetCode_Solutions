class Solution {
public:
    vector<vector<int>> generate(int number) {
        vector<vector<int>> requiredVector;

        for(int i = 0; i < number; i++){
            vector<int> smallerVector;

            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    smallerVector.push_back(1);
                } else {
                    int sumToPush = requiredVector[i - 1][j - 1] + requiredVector[i - 1][j];
                    smallerVector.push_back(sumToPush);
                }
            }
            requiredVector.push_back(smallerVector);
        }

        return requiredVector;
    }
};
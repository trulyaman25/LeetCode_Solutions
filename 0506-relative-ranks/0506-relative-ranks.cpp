class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& assetVector) {
        vector<pair<int,int>> pairs;

        int vectorLength = assetVector.size();
        for (int i = 0; i < vectorLength; i++) {
            pairs.push_back({assetVector[i],i});
        }
        
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>> ());
        vector<string> resultantVector(vectorLength);
        for (int i = 0; i < vectorLength; i++) {
            if (i == 0) {
                resultantVector[pairs[i].second] = "Gold Medal";
            } else if (i == 1) {
                resultantVector[pairs[i].second] = "Silver Medal";
            } else if (i == 2) {
                resultantVector[pairs[i].second]="Bronze Medal";
            } else {
                resultantVector[pairs[i].second] = to_string(i+1);
            }
        }
        
        return resultantVector;
    }
};
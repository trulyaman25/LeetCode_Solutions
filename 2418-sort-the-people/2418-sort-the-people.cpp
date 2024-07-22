class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> sortedPeople;
        for(int i = 0; i < heights.size(); i++){
            sortedPeople[heights[i]] = names[i];
        }

        vector<string> resultantVector;
        for(auto it : sortedPeople){
            resultantVector.push_back(it.second);
        }

        reverse(resultantVector.begin(), resultantVector.end());

        return resultantVector;
    }
};
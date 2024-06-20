class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = INT_MIN;
        for(int i = 0; i < candies.size(); i++){
            maxCandies = max(maxCandies, candies[i]);
        }

        vector<bool> result;
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maxCandies){
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};
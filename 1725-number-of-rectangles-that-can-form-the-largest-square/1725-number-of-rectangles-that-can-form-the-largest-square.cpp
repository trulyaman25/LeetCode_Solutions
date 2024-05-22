class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> vector;
        for(int i = 0; i < rectangles.size(); i++){
            vector.push_back(min(rectangles[i][0], rectangles[i][1]));
        }
        int max = INT_MIN;
        for(auto it : vector){
            if(it > max){
                max = it;
            }
        }
        int count = 0;
        for(auto it : vector){
            if(it == max){
                count++;
            }
        }

        return count;
    }
};
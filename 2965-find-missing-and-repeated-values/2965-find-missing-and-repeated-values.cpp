class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeatedNumber = 0;
        int missingNumber = grid.size() * grid[0].size();

        map<int, int> hashMap;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                hashMap[grid[i][j]]++;
                if(hashMap[grid[i][j]] > 1){
                    repeatedNumber = grid[i][j];
                }
            }
        }

        int count = 1;
        for(auto it : hashMap){
            if(it.first != count){
                missingNumber = count;
                break;
            }
            count++;
        }

        return {repeatedNumber, missingNumber};
    }
};
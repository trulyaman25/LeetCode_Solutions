class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& nums) {
        vector<int> result(2, -1);

        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = 0; j < nums[i].size(); j++){
                sum += nums[i][j];
            }

            if(sum > result[1]){
                result[0] = i;
                result[1] = sum;
            }
        }

        return result;
    }
};
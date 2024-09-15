class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> resultantVector;
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
            if(hashMap[nums[i]] > 1){
                resultantVector.push_back(nums[i]);
            }
        }

        return resultantVector;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
        }

        for(auto it : hashMap){
            if(it.second > nums.size() / 2){
                return it.first;
            }
        }

        return 0;
    }
};
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                int product = nums[i] * nums[j];
                count += 8 * hashMap[product];
                hashMap[product]++;
            }
        }

        return count;
    }
};
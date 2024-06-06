class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0){
            return false;
        }

        map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
        }

        while(!hashMap.empty()){
            int startNumber = hashMap.begin()->first;
            for(int i = 0; i < k; i++){
                int nextNumber = startNumber + i;
                if(hashMap[nextNumber] == 0){
                    return false;
                }

                if(--hashMap[nextNumber] == 0){
                    hashMap.erase(nextNumber);
                }
            }
        }

        return true;
    }
};
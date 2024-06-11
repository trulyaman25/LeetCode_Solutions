class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0){
            return false;
        }
        if(nums.size() == 2 && nums[0] == nums[1]){
            return true;
        }
        if(k + 1 > nums.size()){
            return false;
        }

        int pointerOne = 0;
        int pointerTwo = 0;
        
        unordered_map<int, int> hashMap;
        while(pointerTwo <= k){
            hashMap[nums[pointerTwo]]++;
            if(hashMap[nums[pointerTwo]] > 1){
                return true;
            }
            pointerTwo++;
        }

        while(pointerTwo < nums.size()){
            if(hashMap[nums[pointerOne]] > 0){
                hashMap[nums[pointerOne]]--;
            }
            hashMap[nums[pointerTwo]]++;
            
            if(hashMap[nums[pointerTwo]] > 1){
                return true;
            }

            pointerOne++;
            pointerTwo++;
        }

        return false;
    }
};
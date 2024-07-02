class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> resultantVector;
        unordered_map<int, int> hashMap;

        if(nums1.size() > nums2.size()){
            for(int i = 0; i < nums1.size(); i++){
                hashMap[nums1[i]]++;
            }
            for(int i = 0; i < nums2.size(); i++){
                if(hashMap.count(nums2[i]) > 0){
                    resultantVector.push_back(nums2[i]);
                }
            }
        } else {
            for(int i = 0; i < nums2.size(); i++){
                hashMap[nums2[i]]++;
            }
            for(int i = 0; i < nums1.size(); i++){
                if(hashMap.count(nums1[i]) > 0){
                    resultantVector.push_back(nums1[i]);
                }
            }
        }

        return resultantVector;
    }
};
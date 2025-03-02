class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> hashMap;
        for (int i = 0; i < nums1.size(); i++) {
            hashMap[nums1[i][0]] = nums1[i][1];
        }

        for (int i = 0; i < nums2.size(); i++) {
            hashMap[nums2[i][0]] += nums2[i][1];
        }

        vector<vector<int>> resultantVector;
        for (auto it : hashMap) {
            resultantVector.push_back({it.first, it.second});
        }

        return resultantVector;
    }
};

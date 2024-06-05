class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> frequencyVectorOne(1001, 0);
        vector<int> frequencyVectorTwo(1001, 0);

        for(int i = 0; i < nums1.size(); i++){
            frequencyVectorOne[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            frequencyVectorTwo[nums2[i]]++;
        }

        vector<int> resultantVector;
        for(int i = 0; i < 1001; i++){
            int count = min(frequencyVectorOne[i], frequencyVectorTwo[i]);
            while(count > 0){
                resultantVector.push_back(i);
                count--;
            }
        }
        return resultantVector;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto it : hashMap){
            minHeap.push(make_pair(it.first, it.second));
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> resultantVector;
        while(minHeap.size() > 0){
            resultantVector.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return resultantVector;
    }
};
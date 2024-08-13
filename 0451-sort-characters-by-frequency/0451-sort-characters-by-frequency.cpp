class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashMap;
        for(int i = 0; i < s.length(); i++){
            hashMap[s[i]]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto it : hashMap){
            maxHeap.push(make_pair(it.second, it.first));
        }

        string resultantString;
        while(maxHeap.size() > 0){
            int frequency = maxHeap.top().first;
            while(frequency--){
                resultantString += maxHeap.top().second;
            }
            maxHeap.pop();
        }

        return resultantString;
    }
};
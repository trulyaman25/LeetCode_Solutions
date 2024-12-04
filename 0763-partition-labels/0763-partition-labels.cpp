class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> hashMap;
        for (int i = 0; i < s.length(); i++) {
            if (hashMap.find(s[i]) == hashMap.end()) {
                int start = i;
                int end = i;
                pair<int, int> range = make_pair(start, end);
                hashMap[s[i]] = range;
            } else {
                hashMap[s[i]].second = i;
            }
        }

        vector<int> resultantVector;
        vector<pair<int, int>> assetVector;
        for(auto it : hashMap){
            assetVector.push_back(it.second);
        }

        sort(assetVector.begin(), assetVector.end());

        int currentLength = 0;
        int threshold = assetVector[0].second;
        for (int i = 0; i < assetVector.size(); i++) {
            threshold = max(threshold, assetVector[i].second);
            if (i == assetVector.size() - 1 || threshold < assetVector[i + 1].first) {
                resultantVector.push_back(threshold - currentLength + 1);
                currentLength = threshold + 1;
            }
        }

        cout << threshold << endl;

        return resultantVector;
    }
};
class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> hashMap;
        for (auto it : s) {
            hashMap[it]++;
        }

        int maxFrequency = INT_MIN;
        for (auto it : hashMap) {
            if (it.second > maxFrequency) {
                maxFrequency = it.second;
            }
        }

        string resultantString;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (hashMap[s[i]] == maxFrequency) {
                resultantString += s[i];
                hashMap[s[i]]--;
            }
        }

        reverse(resultantString.begin(), resultantString.end());

        return resultantString;
    }
};
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> resultantVector;
        unordered_map<string, int> hashMap;
        string word = "";

        for (int i = 0; i <= s1.length(); i++) {
            if (i == s1.length() || s1[i] == ' ') {
                if (!word.empty()) {
                    hashMap[word]++;
                    word = "";
                }
            } else {
                word += s1[i];
            }
        }

        for (int i = 0; i <= s2.length(); i++) {
            if (i == s2.length() || s2[i] == ' ') {
                if (!word.empty()) {
                    hashMap[word]++;
                    word = "";
                }
            } else {
                word += s2[i];
            }
        }

        for (auto it : hashMap) {
            if (it.second == 1) {
                resultantVector.push_back(it.first);
            }
        }

        return resultantVector;
    }
};

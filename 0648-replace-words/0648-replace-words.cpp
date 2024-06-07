class Solution {
public:
    string replaceWords(vector<string>& dictionary, string text) {
        unordered_map<string, int> hashMap;
        for(int i = 0; i < dictionary.size(); i++){
            hashMap[dictionary[i]]++;
        }

        vector<string> words;
        int previousSpace = -1;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                int start = previousSpace + 1;
                int length = i - start;
                if (length > 0) {
                    words.push_back(text.substr(start, length));
                }
                previousSpace = i;
            }
        }

        string result = "";
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                if(hashMap[words[i].substr(0, j)] == 1){
                    words[i] = words[i].substr(0, j);
                }
            }
            
            if(i == words.size() - 1){
                result += words[i];
            } else {
                result += words[i] + " ";
            }
        }

        return result;
    }
};
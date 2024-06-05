class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int rows = words.size();
        vector<vector<int>> frequencyVector(rows, vector<int>(26, 0));
        for(int i = 0; i < rows; i++){
            string word = words[i];
            for(int j = 0; j < word.length(); j++){
                frequencyVector[i][word[j] - 'a']++; 
            }
        }

        vector<string> resultantVector;
        for(int i = 0; i < 26; i++){
            int count = INT_MAX;
            for(int j = 0; j < rows; j++){
                count = min(count, frequencyVector[j][i]);
            }
            while(count){
                char targetCharacter = i + 'a';
                string targetString = "";
                targetString += targetCharacter;
                resultantVector.push_back(targetString);
                count--;
            }
        }
        return resultantVector;
    }
};
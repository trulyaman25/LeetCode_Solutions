class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rOne = "qwertyuiopQWERTYUIOP";
        unordered_map<char, int> rowOne;
        for(int i = 0; i < rOne.size(); i++){
            rowOne[rOne[i]]++;
        }

        string rTwo = "asdfghjklASDFGHJKL";
        unordered_map<char, int> rowTwo;
        for(int i = 0; i < rTwo.size(); i++){
            rowTwo[rTwo[i]]++;
        }

        string rThree = "zxcvbnmZXCVBNM";
        unordered_map<char, int> rowThree;
        for(int i = 0; i < rThree.size(); i++){
            rowThree[rThree[i]]++;
        }

        vector<string> resultantVector;
        for(int i = 0; i < words.size(); i++){
            char initialChar = words[i][0];
            int selection = 0;
            if(rowOne.count(initialChar) >= 1){
                selection = 1;
            } else if (rowTwo.count(initialChar) >= 1){
                selection = 2;
            } else {
                selection = 3;
            }

            if(selection == 1){
                for(int j = 0; j < words[i].size(); j++){
                    if(rowOne.count(words[i][j]) == 0){
                        break;
                    }
                    if(j == words[i].size() - 1){
                        resultantVector.push_back(words[i]);
                    }
                }
            }
            if(selection == 2){
                for(int j = 0; j < words[i].size(); j++){
                    if(rowTwo.count(words[i][j]) == 0){
                        break;
                    }
                    if(j == words[i].size() - 1){
                        resultantVector.push_back(words[i]);
                    }
                }
            }
            if(selection == 3){
                for(int j = 0; j < words[i].size(); j++){
                    if(rowThree.count(words[i][j]) == 0){
                        break;
                    }
                    if(j == words[i].size() - 1){
                        resultantVector.push_back(words[i]);
                    }
                }
            }
        }

        return resultantVector;
    }
};
class Solution {
public:
    void caseOne(string& assetString, string& resultantString, int& index){
        resultantString += assetString[index];
    }

    void caseTwo(string& assetString, string& resultantString){
        if(resultantString.length() > 0){
            resultantString.pop_back();
        }
    }

    void caseThree(string& assetString, string& resultantString){
        resultantString += resultantString;
    }

    void caseFour(string& assetString, string& resultantString){
        int pointerOne = 0;
        int pointerTwo = resultantString.length() - 1;

        while(pointerOne < pointerTwo){
            swap(resultantString[pointerOne], resultantString[pointerTwo]);
            pointerOne++;
            pointerTwo--;
        }
    }

    string processStr(string s) {
        string resultantString;

        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                caseOne(s, resultantString, i);
            } else if (s[i] == '*'){
                caseTwo(s, resultantString);
            } else if (s[i] == '#'){
                caseThree(s, resultantString);
            } else if (s[i] == '%'){
                caseFour(s, resultantString);
            }
        }

        return resultantString;
    }
};
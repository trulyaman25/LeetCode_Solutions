class Solution {
private:
    bool check(string inputString, int k) {
        map<char,int>hashMapOne;
        for(int i = 0; i < k; i++){
            hashMapOne[inputString[i]]++;
        }

        for(int i = k; i < inputString.size(); i += k){
            if(i + k > inputString.size()){
                return 0;
            }

            map<char,int> hashMapTwo;
            for(int j = i; j < i + k; j++){
                hashMapTwo[inputString[j]]++;
            }

            if(hashMapOne != hashMapTwo){
                return 0; 
            }
        }

        return 1;
    }
    
public:

    int minAnagramLength(string inputString) {
        for(int i = 1; i <= inputString.length(); i++){
            if(inputString.length() % i == 0 && check(inputString, i)){
                return i;
            }
        }

        return inputString.length();
    }
};
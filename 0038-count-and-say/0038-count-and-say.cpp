class Solution {
public:
    string call(int number){
        if(number == 1){
            return "1";
        }

        int count = 1;

        string previousRLE = call(number - 1);
        string encodedString = "";
        for(int i = 0; i < previousRLE.length(); i++){
            if(previousRLE[i] == previousRLE[i + 1]){
                count++;
            } else {
                encodedString += to_string(count) + previousRLE[i];
                count = 1;
            }
        }

        return encodedString;
    }

    string countAndSay(int n) {
        string encodedString = call(n);

        return encodedString;
    }
};
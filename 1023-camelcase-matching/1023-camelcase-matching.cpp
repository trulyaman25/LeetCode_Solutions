class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> resultantVector;
        for(int i = 0; i < queries.size(); i++){
            string assetString = queries[i];
            
            int pointerOne = 0;
            int pointerTwo = 0;
            bool validity = true;
            while(pointerOne < assetString.length() && pointerTwo < pattern.length()){
                if(assetString[pointerOne] == pattern[pointerTwo]){
                    pointerOne++;
                    pointerTwo++;
                } else {
                    if(isupper(assetString[pointerOne])){
                        validity = false;
                        break;
                    }
                    pointerOne++;
                }
            }

            if(pointerTwo < pattern.length()){
                validity = false;
            }

            while(validity && pointerOne < assetString.length()){
                if(isupper(assetString[pointerOne])){
                        validity = false;
                        break;
                    }
                    pointerOne++;
            }

            resultantVector.push_back(validity);
        }
        return resultantVector;
    }
};
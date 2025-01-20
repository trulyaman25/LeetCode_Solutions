class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        int pointerOne = 0;
        int pointerTwo = 0;

        unordered_map<char, int> patternMap;
        for(int i = 0; i < pat.length(); i++){
            patternMap[pat[i]]++;
        }
        
        int uniqueCount = patternMap.size();
        int anagramCount = 0;
        
        while(pointerTwo < pat.length()){
            if(patternMap.count(txt[pointerTwo])){
                patternMap[txt[pointerTwo]]--;
                if(patternMap[txt[pointerTwo]] == 0){
                    uniqueCount--;
                }
            }
            
            pointerTwo++;
        }
        
        vector<int> resultantVector;

        if(uniqueCount == 0){
            resultantVector.push_back(pointerOne);
        }
        
        while(pointerTwo < txt.length()){
            if(patternMap.count(txt[pointerTwo])){
                patternMap[txt[pointerTwo]]--;
                if(patternMap[txt[pointerTwo]] == 0){
                    uniqueCount--;
                }
            }
            
            if(patternMap.count(txt[pointerOne])){
                if(patternMap[txt[pointerOne]] == 0){
                    uniqueCount++;
                }
                patternMap[txt[pointerOne]]++;
            }
            
            if(uniqueCount == 0){
                resultantVector.push_back(pointerOne + 1);
            }
        
            pointerOne++;
            pointerTwo++;
        }
        
        return resultantVector;
    }
};
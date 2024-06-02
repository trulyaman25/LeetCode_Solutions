class Solution {
public:
    int minimumChairs(string s) {
        int chairCount = 0;
        int maxChair = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'E'){
                chairCount++;
                maxChair = max(maxChair, chairCount);
            } else {
                chairCount--;
            }
        }
        return maxChair;
    }
};
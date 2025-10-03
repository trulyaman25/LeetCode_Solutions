class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        unordered_map<char, int> hashMap;

        int leftPointer = 0;
        int rightPointer = 0;
        while(rightPointer < s.length()){
            hashMap[s[rightPointer]]++;
            while(hashMap.size() == 3){
                count += s.length() - rightPointer;
                hashMap[s[leftPointer]]--;
                if(hashMap[s[leftPointer]] == 0){
                    hashMap.erase(s[leftPointer]);
                }
                leftPointer++;
            }
            rightPointer++;
        }

        return count;
    }
};
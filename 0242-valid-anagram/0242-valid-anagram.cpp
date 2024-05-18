// Approach 1 (Genuine)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length()){
//             return false;
//         }

//         int length = t.length() - 1;
//         unordered_map<char, int> hashMap;
//         for(int i = 0;  i < length + 1; i++){
//             hashMap[s[i]]++;
//             hashMap[t[i]]--;
//         }

//         for(auto it : hashMap){
//             if(it.second != 0){
//                 return false;
//             }
//         }

//         return true;
//     }
// };


//Approach 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
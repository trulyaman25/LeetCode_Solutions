// class Solution {
// public:
//     double get(string s ){
//          double t =0.0;
//          for(int i=0;i<s.size();i++){
//             t= t*10.0 + 1.0*(s[i]-'0');
//          }
//          return t;
//     }
//     string kthLargestNumber(vector<string>& nums, int k) {
//         priority_queue<double,vector<double>,greater<double>>pq;
//         for(auto i :  nums){
//             double t = get(i);
//             pq.push(t);
//             if(pq.size()>k) pq.pop();
//         }
//         return to_string((int long long)pq.top());
//     }
// };


class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
         auto comp = [](string  &a, string &b) {
            if(a.size() == b.size()) {
                return a > b;
            }
            return a.size() > b.size();
        };

        priority_queue< string, vector<string>, decltype(comp) >pq(comp);
        for(auto &it : nums) {
            pq.push(it);
            if(pq.size() > k)pq.pop();
        }
        return pq.top();
    }
};
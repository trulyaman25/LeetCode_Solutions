class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for(int i = 0; i < k; i++){
            sort(gifts.begin(), gifts.end());

            int value = gifts.back();
            gifts.pop_back();
            gifts.push_back(sqrt(value));
        }

        long long sum = 0;
        for(int i = 0; i < gifts.size(); i++){
            sum += gifts[i];
        }

        return sum;
    }
};
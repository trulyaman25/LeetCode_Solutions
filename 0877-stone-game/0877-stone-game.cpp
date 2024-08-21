class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int aliceCount = 0;
        int bobCount = 0;

        int count = piles.size();
        bool flag = true;
        while(count--){
            if(flag){
                if(piles[0] > piles.back()){
                    aliceCount += piles[0];
                    piles.erase(piles.begin());
                } else {
                    aliceCount += piles.back();
                    piles.pop_back();
                }
                
                flag = false;
            } else {
                if(piles[0] > piles.back()){
                    bobCount += piles[0];
                    piles.erase(piles.begin());
                } else {
                    bobCount += piles.back();
                    piles.pop_back();
                }
                
                flag = true;
            }
        }

        if(aliceCount < bobCount){
            return false;
        }

        return true;
    }
};
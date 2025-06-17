// TC - O(n)
// SC - O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;
        int twentyCount = 0;

        for(int i = 0; i < bills.size(); i++){
            int billGiven = bills[i];
            int changeRequired = billGiven - 5;

            if(changeRequired == 5){
                if(fiveCount >= 1){
                    fiveCount--;
                } else {
                    return false;
                }
            } else if(changeRequired == 15){
                if(fiveCount >= 3){
                    fiveCount -= 3;
                } else if (fiveCount >= 1 && tenCount >= 1){
                    fiveCount -= 1;
                    tenCount -= 1;
                } else {
                    return false;
                }
            }

            if(billGiven == 5){
                fiveCount++;
            } else if (billGiven == 10){
                tenCount++;
            } else {
                twentyCount++;
            }
        }

        return true;
    }
};
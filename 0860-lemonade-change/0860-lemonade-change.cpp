class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                fiveCount++;
            } else if(bills[i] == 10){
                tenCount++;
                fiveCount--;
                if(fiveCount < 0){
                    return false;
                }
            } else {
                if(tenCount > 0){
                    tenCount--;
                    if(fiveCount > 0){
                        fiveCount--;
                        if(fiveCount < 0){
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else if(fiveCount >= 3){
                    fiveCount -= 3;
                        if(fiveCount < 0){
                            return false;
                        }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size() == 1){
//             return 0;
//         }

//         int profit = 0;
//         int maxProfit = 0;
//         for(int i = 1; i < prices.size(); i++){
//             profit += prices[i] - prices[i - 1];
//             if(profit > 0){
//                 maxProfit += profit;
//                 profit = 0;
//             }
//             if(profit < 0){
//                 profit = 0;
//             }
//         }

//         return maxProfit;
//     }
// };

//BETTER SOLUTION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;

        int prefixProduct = 1;
        int suffixProduct = 1;
        for(int i = 0; i < nums.size(); i++){
            prefixProduct *= nums[i];
            maxProduct = max(maxProduct, prefixProduct);

            suffixProduct *= nums[nums.size() - i - 1];
            maxProduct = max(maxProduct, suffixProduct);

            if(prefixProduct == 0){
                prefixProduct = 1;
            }

            if(suffixProduct == 0){
                suffixProduct = 1;
            }
        }

        return maxProduct;
    }
};
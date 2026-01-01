class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int currentDigit = digits[i];
            int sum = currentDigit + carry;
            
            if(sum <= 9){
                digits[i] = sum;
                return digits;
            }

            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if(carry){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
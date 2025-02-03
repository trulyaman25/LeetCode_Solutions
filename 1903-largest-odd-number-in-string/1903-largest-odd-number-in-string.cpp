class Solution {
public:
    string largestOddNumber(string nums) {
        string longestString = "";
        string currentString = "";
        for(int i = 0; i < nums.size(); i++){
            currentString += nums[i];
            if( currentString.back() == '1' || 
                currentString.back() == '3' || 
                currentString.back() == '5' || 
                currentString.back() == '7' || 
                currentString.back() == '9' ) {
                    longestString = currentString;
            }
        }

        return longestString;
    }
};
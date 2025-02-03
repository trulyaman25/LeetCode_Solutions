class Solution {
public:
    string largestOddNumber(string nums) {
        string longestString = "";
        string currentString = "";
        for(int i = nums.size() - 1; i >= 0; i--){
            if( nums[i] == '1' || nums[i] == '3' || nums[i] == '5' || nums[i] == '7' || nums[i] == '9' ) {
                    longestString = nums.substr(0, i + 1);
                    break;
            }
        }

        return longestString;
    }
};
class Solution {
public:
    string largestOddNumber(string nums) {
        string largestOdd = "";
        string currentString = "";
        for(int i = 0; i < nums.size(); i++){
            currentString += nums[i];
            int intValue = stoi(currentString);
            if(intValue % 2 != 0){
                if(currentString.length() >= largestOdd.length()){
                    largestOdd = currentString;
                }   
            }
        }

        return largestOdd;
    }
};
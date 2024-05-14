class Solution {
public:
    string formBinary(int number, int length){
        if(number == 0){
            return "0";
        }

        string binary = "";
        while(number){
            int remainder = number % 2;
            binary = to_string(remainder) + binary;
            number /= 2;
        }

        binary = string(length - binary.length(), '0') + binary;

        return binary;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
        }

        int maxInt = pow(2, nums.size()) - 1;

        while(maxInt >= 0){
            string target = formBinary(maxInt--, nums.size());
            if(hashMap[target] <= 0){
                return target;
            }
        }

        return "";
    }
};
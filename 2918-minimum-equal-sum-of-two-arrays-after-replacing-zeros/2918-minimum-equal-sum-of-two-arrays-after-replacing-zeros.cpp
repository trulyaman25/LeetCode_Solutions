class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sumOne = 0;
        long long zeroCountOne = 0;
        for(int i = 0; i < nums1.size(); i++){
            sumOne += nums1[i];
            if(nums1[i] == 0) zeroCountOne++;
        }

        long long sumTwo = 0;
        long long zeroCountTwo = 0;
        for(int i = 0; i < nums2.size(); i++){
            sumTwo += nums2[i];
            if(nums2[i] == 0) zeroCountTwo++;
        }

        if(zeroCountTwo == 0 && sumTwo < sumOne){
            return -1;
        }
        if(zeroCountOne == 0 && sumTwo > sumOne){
            return -1;
        }
        if(zeroCountOne == 0 && zeroCountTwo == 0 && sumOne != sumTwo){
            return -1;
        }
        if(zeroCountOne == 0 && zeroCountTwo != 0 && sumOne == sumTwo){
            return -1;
        }    
        if(sumOne == sumTwo && zeroCountOne == 0 && zeroCountTwo != 0){
            return -1;
        }    
        if(sumOne == sumTwo && zeroCountOne != 0 && zeroCountTwo == 0){
            return -1;
        }    

        if(sumTwo > sumOne){
            sumTwo += zeroCountTwo;
            zeroCountTwo = 0;

            sumOne += zeroCountOne;
            zeroCountOne = 0;
            while(sumOne < sumTwo){
                sumOne++;
            }

            if(sumOne == sumTwo){
                return sumOne;
            } else {
                return -1;
            }
        }

        sumOne += zeroCountOne;
        zeroCountOne = 0;

        sumTwo += zeroCountTwo;
        zeroCountTwo = 0;
        while(sumTwo < sumOne){
            sumTwo++;
        }

        if(sumOne == sumTwo){
            return sumOne;
        } else {
            return -1;
        }
    }
};
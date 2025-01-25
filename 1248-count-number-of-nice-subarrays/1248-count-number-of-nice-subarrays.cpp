class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int partOne = countOdd(nums, k);
        int partTwo = countOdd(nums, k - 1);

        return partOne - partTwo;
    }

    int countOdd(vector<int>& nums, int k){
        int pointerOne = 0;
        int pointerTwo = 0;
        int oddCount = 0;
        int subarrayCount = 0;

        while(pointerTwo < nums.size()){
            if(nums[pointerTwo] % 2 != 0){
                oddCount++;
            }

            while(oddCount > k){
                if(nums[pointerOne] % 2 != 0){
                    oddCount--;
                }

                pointerOne++;
            }

            subarrayCount += pointerTwo - pointerOne + 1;

            pointerTwo++;
        }

        return subarrayCount;
    }
};
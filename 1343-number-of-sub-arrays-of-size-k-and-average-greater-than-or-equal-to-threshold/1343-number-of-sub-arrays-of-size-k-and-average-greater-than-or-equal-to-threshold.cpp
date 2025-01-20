class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int count = 0;
        int sum = 0;
        int average = 0;

        int pointerOne = 0;
        int pointerTwo = 0;
        while(pointerTwo < k){
            sum += nums[pointerTwo];

            pointerTwo++;
        }

        average = sum / k;

        if(average >= threshold){
            count++;
        }

        while(pointerTwo < nums.size()){
            sum += nums[pointerTwo];
            sum -= nums[pointerOne];

            average = sum / k;

            if(average >= threshold){
                count++;
            }

            pointerOne++;
            pointerTwo++;
        }

        return count;
    }
};
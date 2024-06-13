class Solution {
public:
    int mySqrt(int x) {
        int leftPointer = 0;
        int rightPointer = x;

        while(leftPointer <= rightPointer){
            long long midPointer = (leftPointer + rightPointer) / 2;

            if(midPointer * midPointer == x){
                return midPointer;
            } else if(midPointer * midPointer > x){
                rightPointer = midPointer - 1;
            } else {
                leftPointer = midPointer + 1;
            }
        }

        return rightPointer;
    }
};
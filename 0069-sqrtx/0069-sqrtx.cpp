class Solution {
public:
    int mySqrt(int x) {
        int pointerOne = 0;
        int pointerTwo = x;

        while(pointerOne <= pointerTwo){
            long long mid = pointerOne + (pointerTwo - pointerOne) / 2;
            
            if(mid * mid == x){
                return mid;
            } else if (mid * mid < x) {
                pointerOne = mid + 1;
            } else {
                pointerTwo = mid - 1;
            }
        }

        return pointerTwo;
    }
};
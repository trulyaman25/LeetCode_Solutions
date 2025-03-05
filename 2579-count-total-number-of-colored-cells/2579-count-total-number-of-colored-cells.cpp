class Solution {
public:
    long long coloredCells(int n) {
        long long nCount = (long long)n * (long long)n;
        long long newCount = (long long)(n - 1) * (long long)(n - 1);

        long long result = nCount + newCount;
        return result;
    }
};
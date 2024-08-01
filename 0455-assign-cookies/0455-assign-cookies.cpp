class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gPointer = 0;
        int sPointer = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (gPointer < g.size() && sPointer < s.size()) {
            if (s[sPointer] >= g[gPointer]) {
                gPointer++;
            }
            sPointer++;
        }

        return gPointer;
    }
};
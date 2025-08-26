class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()){
            return 0;
        }

        stack<int> assetStack;  
        assetStack.push(-1);

        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                assetStack.push(i);
            } else {
                assetStack.pop();
                if (assetStack.empty()) {
                    assetStack.push(i);
                } else {
                    maxLength = max(maxLength, i - assetStack.top());
                }
            }
        }

        return maxLength;
    }
};
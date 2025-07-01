class Solution {
public:
    bool isValid(string s) {
        stack<char> assetStack;
        
        for(int i = 0; i < s.length(); i++){
            if(assetStack.empty()){
                assetStack.push(s[i]);
            } else {
                if(
                    assetStack.top() == '(' && s[i] == ')' || 
                    assetStack.top() == '[' && s[i] == ']' ||
                    assetStack.top() == '{' && s[i] == '}'
                ){
                    assetStack.pop();
                } else {
                    assetStack.push(s[i]);
                }
            }
        }

        return assetStack.empty();
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for(int i = 0; i < s.length(); i++){
            if(!stack.empty() && 
               (stack.top() == '(' && s[i] == ')' ||
                stack.top() == '{' && s[i] == '}' ||
                stack.top() == '[' && s[i] == ']')){
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }

        return stack.empty();
    }
};
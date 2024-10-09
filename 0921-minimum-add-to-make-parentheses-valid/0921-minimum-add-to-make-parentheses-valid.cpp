class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || stack.empty() || stack.top() ==')'){
                stack.push(s[i]);
            } else {
                if(stack.size() != 0 && stack.top() == '('){
                    stack.pop();
                }
            }
        }

        return stack.size();
    }
};
class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        stack<string> stack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                word += s[i];
            } else {
                if(word != ""){
                    stack.push(word);
                    word = "";
                }
            }
        }

        if(word != ""){
            stack.push(word);
        }

        string resultantString;
        while(!stack.empty()){
            resultantString += stack.top() + " ";
            stack.pop();
        }

        resultantString.pop_back();

        return resultantString;
    }
};
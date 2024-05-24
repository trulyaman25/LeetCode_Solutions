class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> stack;
        for(int i = sandwiches.size() - 1; i >= 0; i--){
            stack.push(sandwiches[i]);
        }

        queue<int> queue;
        for(int i = 0; i < students.size(); i++){
            queue.push(students[i]);
        }

        int count = 0;
        while(!stack.empty() && count < students.size()){
            if(queue.front() == stack.top()){
                queue.pop();
                stack.pop();
                count = 0;
            } else {
                queue.push(queue.front());
                queue.pop();
                count++;
            }
        }

        return queue.size();
    }
};
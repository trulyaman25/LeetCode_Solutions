class MinStack {
private:
    vector<long long int> stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.erase(stack.end() - 1);
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        int min = INT_MAX;
        for(int i = 0; i < stack.size(); i++){
            if(stack[i] < min){
                min = stack[i];
            }
        }

        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
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
        vector<long long int> dataVector = stack;
        sort(dataVector.begin(), dataVector.end());
        return dataVector[0];
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
class MinStack {
private:
    stack<pair<int, int>> assetStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minValue = INT_MAX;
        
        if(assetStack.empty()){
            minValue = val;
        } else {
            minValue = min(assetStack.top().second, val);
        }

        assetStack.push({val, minValue});
    }
    
    void pop() {
        assetStack.pop();
    }
    
    int top() {
        return assetStack.top().first;
    }
    
    int getMin() {
        return assetStack.top().second;
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
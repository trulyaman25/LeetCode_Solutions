class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> monoStack;
        
        vector<int> resultantVector(nums.size(), 0);
        for(int i = 2 * nums.size() - 1; i >= 0; i--){
            int currentNumber = nums[i % nums.size()];

            while(!monoStack.empty() && monoStack.top() <= currentNumber){
                monoStack.pop();
            }

            int nextGreater = 0;
            if(monoStack.empty()){
                nextGreater = -1;
            } else {
                nextGreater = monoStack.top();
            }

            if(i < nums.size()){
                resultantVector[i] = nextGreater;
            }

            monoStack.push(currentNumber);
        }
        
        return resultantVector;
    }
};
class Solution {
public:
    int pairSum(ListNode* head) {
        int length = 0;
        ListNode* tempHead = head;
        while (tempHead) {
            length++;
            tempHead = tempHead->next;
        }


        int count = 0;
        int maxSum = 0;
        int midPoint = length / 2;

        tempHead = head;
        stack<int> stack;
        while (tempHead) {
            if (count < midPoint) {
                stack.push(tempHead->val);
            } else {
                if (!stack.empty()) {
                    int sum = tempHead->val + stack.top();
                    maxSum = max(maxSum, sum);
                    stack.pop();
                }
            }
            count++;
            tempHead = tempHead->next;
        }

        return maxSum;
    }
};
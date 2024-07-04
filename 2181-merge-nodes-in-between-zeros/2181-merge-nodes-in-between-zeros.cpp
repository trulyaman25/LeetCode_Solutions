class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tempHead = head->next;
        int sum = 0;

        ListNode* newHead = new ListNode();
        ListNode* mover = newHead;
        while(tempHead){
            sum += tempHead->val;

            if(tempHead->val == 0){
                ListNode* newNode = new ListNode(sum);
                mover->next = newNode;
                mover = mover->next;
                sum = 0;
            }

            tempHead = tempHead->next;
        }

        return newHead->next;
    }
};
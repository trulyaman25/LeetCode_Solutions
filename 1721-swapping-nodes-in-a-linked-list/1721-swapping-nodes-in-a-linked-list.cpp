class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* nodeOne = nullptr;
        ListNode* nodeTwo = nullptr;

        int length = 0;
        ListNode* tempHead = head;
        while(tempHead){
            length++;
            tempHead = tempHead->next;
        }

        int count = 0;
        tempHead = head;
        while(tempHead){
            count++;

            if(count == k){
                nodeOne = tempHead;
            }

            if (count == length - k + 1){
                nodeTwo = tempHead;
            }

            tempHead = tempHead->next;
        }
        swap(nodeOne->val, nodeTwo->val);

        return head;
    }
};
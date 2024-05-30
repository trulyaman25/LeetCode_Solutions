//BRUTE FORCE
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* tempHead = head;
        int count = 0;
        while(tempHead){
            count++;
            tempHead = tempHead->next;
        }

        int targetIndex = ceil(count / 2) - 1;
        cout << targetIndex;

        tempHead = head;
        count = 0;
        while(count < targetIndex){
            count++;
            tempHead = tempHead->next;
        }

        ListNode* targetNode = tempHead->next;
        tempHead->next = targetNode->next;
        delete targetNode;

        return head;
    }
};
//BRUTE FORCE SOLUTION
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //EDGE CASE 1: When the linked list is already empty
        if(head == NULL){
            return head;
        }

        ListNode* tempHead = head;
        int count = 0;
        //Loop to find the length of the linked list
        while(tempHead){
            count++;
            tempHead = tempHead->next;
        }

        //Edge Case 2: If the head node is to be deleted (i.e: n == length)
        if(count == n){
            ListNode* oldHead = head;
            head = oldHead->next;
            delete oldHead;
            return head;
        }

        int targetIndex = count - n;
        count = 0;
        tempHead = head;
        //Loop to find the target index in the linked list
        while(count < targetIndex - 1){
            count++;
            tempHead = tempHead->next;
        }

        ListNode* targetNode = tempHead->next;
        tempHead->next = targetNode->next;
        delete targetNode;

        return head;
    }
};
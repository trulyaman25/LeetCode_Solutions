class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* tempHead = head;
        while(tempHead->next){
            int requiredGCD = __gcd(tempHead->val, tempHead->next->val);
            ListNode* newNode = new ListNode(requiredGCD, tempHead->next);

            tempHead->next = newNode;
            tempHead = newNode->next;
        }

        return head;
    }
};
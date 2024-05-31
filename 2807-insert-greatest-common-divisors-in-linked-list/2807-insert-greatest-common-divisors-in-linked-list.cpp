class Solution {
public:
    int gcd(int numberOne, int numberTwo) {
        while (numberTwo) {
            int temp = numberTwo;
            numberTwo = numberOne % numberTwo;
            numberOne = temp;
        }
        return numberOne;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* tempHead = head;
        while(tempHead->next){
            int requiredGCD = gcd(tempHead->val, tempHead->next->val);
            ListNode* newNode = new ListNode(requiredGCD, tempHead->next);

            tempHead->next = newNode;
            tempHead = newNode->next;
        }

        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* headOne, ListNode* headTwo) {
        ListNode* tempHeadOne = headOne;
        ListNode* tempHeadTwo = headTwo;

        bool carryBit = false;
        int sum = tempHeadOne->val + tempHeadTwo->val;
        carryBit = sum >= 10;
        sum = sum % 10;

        tempHeadOne = tempHeadOne->next;
        tempHeadTwo = tempHeadTwo->next;

        ListNode* newHead = new ListNode(sum);
        ListNode* mover = newHead;
        while(tempHeadOne && tempHeadTwo){
            int sum = tempHeadOne->val + tempHeadTwo->val + carryBit;
            carryBit = sum >= 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            mover->next = newNode;
            mover = mover->next;
            tempHeadOne = tempHeadOne->next;
            tempHeadTwo = tempHeadTwo->next;
        }

        if(tempHeadOne != NULL){
            while(tempHeadOne){
                int sum = tempHeadOne->val + carryBit;
                carryBit = sum >= 10;
                sum = sum % 10;
                ListNode* newNode = new ListNode(sum);
                mover->next = newNode;
                mover = mover->next;
                tempHeadOne = tempHeadOne->next;
            }
        } else {
            while(tempHeadTwo){
                int sum = tempHeadTwo->val + carryBit;
                carryBit = sum >= 10;
                sum = sum % 10;
                ListNode* newNode = new ListNode(sum);
                mover->next = newNode;
                mover = mover->next;
                tempHeadTwo = tempHeadTwo->next;
            }
        }

        if(carryBit){
            ListNode* newNode = new ListNode(carryBit);
            mover->next = newNode;
            mover = mover->next;
        }

        return newHead;
    }
};
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
    int findGCD(int numberOne, int numberTwo){
        while(numberTwo != 0){
            int temp = numberTwo;
            numberTwo = numberOne % numberTwo;
            numberOne = temp;
        }
        return numberOne;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL){
            return head;
        }

        ListNode* tempHead = head;
        while(tempHead->next){
            int gcdValue = findGCD(tempHead->val, tempHead->next->val);

            ListNode* newNode = new ListNode(gcdValue, tempHead->next);
            tempHead->next = newNode;

            tempHead = newNode->next;
        }

        return head;
    }
};
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
    int getLength(ListNode* pointer){
        int length = 0;
        while(pointer){
            length++;
            pointer = pointer->next;
        }

        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        } else if (!head->next){
            return head;
        }

        int totalLength = getLength(head);
        int amountRotated = k % totalLength;

        ListNode*newHead = NULL;

        if(amountRotated == totalLength){
            return head;
        } else {
            ListNode* pointer = head;
            int targetLocation = totalLength - amountRotated - 1;

            while(targetLocation--){
                pointer = pointer->next;
            }

            newHead = pointer->next;
            pointer->next = NULL;

            pointer = newHead;
            while(pointer->next){
                pointer = pointer->next;
            }

            pointer->next = head;
        }

        return newHead;
    }
};
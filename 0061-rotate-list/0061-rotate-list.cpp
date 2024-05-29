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
    int findLength(ListNode* head){
        int length = 0;
        ListNode* tempHead = head;
        while(tempHead){
            length++;
            tempHead = tempHead->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k){
        int totalLength = findLength(head);
        if(head == NULL || head->next == NULL || totalLength == 0){
            return head;
        }

        int rotateIndex = k % totalLength;
        int newListLength = totalLength - rotateIndex;
        
        int count = 0;
        ListNode* tempHead = head;
        while(tempHead->next){
        tempHead = tempHead->next;
        }
        tempHead->next = head;

        count = 0;
        tempHead = head;
        while(count != newListLength - 1){
            tempHead = tempHead->next;
            count++;
        }
        head = tempHead->next;
        tempHead->next = nullptr;

        return head;
    }
};
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
        if(head == nullptr || head->next == nullptr || k % totalLength == 0){
            return head;
        }

        int rotateIndex = k % totalLength;

        int count = 0;
        ListNode* tempHead = head;
        ListNode* newHead = head;
        while(count <= totalLength){
            count++;
            if(count == totalLength - rotateIndex){
                newHead = tempHead->next;
                tempHead->next = nullptr;
                tempHead = newHead;
            } else if(count == totalLength) {
                tempHead->next = head;
            } else {
                tempHead = tempHead->next;
            }
        }

        return newHead;
    }
};
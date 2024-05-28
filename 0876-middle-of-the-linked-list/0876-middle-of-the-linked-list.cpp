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

/*
BRUTE FORCE APPROACH
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* tempHead = head;
        while(tempHead){
            tempHead = tempHead->next;
            length++;
        }

        int mid = ceil(length / 2);
        tempHead = head;
        int count = 0;
        while(count < mid){
            tempHead = tempHead->next;
            count++;
        }

        return tempHead;
    }
};
*/

//OPTIMIZED APPROACH
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
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

 //BRUTE FORCE
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> stack;
        int count = 0;
        ListNode* tempHead = head;
        while(tempHead){
            count++;
            if(count >= left && count <= right){
                stack.push(tempHead->val);
            }
            tempHead = tempHead->next;
        }

        count = 0;
        tempHead = head;
        while(tempHead){
            count++;
            if(count >= left && count <= right){
                tempHead->val = stack.top();
                stack.pop();
            }
            tempHead = tempHead->next;
        }

        return head;
    }
};
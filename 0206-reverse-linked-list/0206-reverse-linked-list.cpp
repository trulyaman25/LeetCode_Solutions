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
 
 //Brute Force Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> stack;

        ListNode* tempHead = head;
        while(tempHead){
            stack.push(tempHead->val);
            tempHead = tempHead->next;
        }

        tempHead = head;
        while(tempHead){
            tempHead->val = stack.top();
            stack.pop();
            tempHead = tempHead->next;
        }

        return head;
    }
};
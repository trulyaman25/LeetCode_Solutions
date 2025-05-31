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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> listOne;
        ListNode* pointer = l1;
        while(pointer){
            listOne.push(pointer->val);
            pointer = pointer->next;
        }

        stack<int> listTwo;
        pointer = l2;
        while(pointer){
            listTwo.push(pointer->val);
            pointer = pointer->next;
        }

        int carry = 0;
        ListNode* nextNode = NULL;
        while (!listOne.empty() || !listTwo.empty() || carry) {
            int one = 0;
            int two = 0;

            if (!listOne.empty()) {
                one = listOne.top();
                listOne.pop();
            }

            if (!listTwo.empty()) {
                two = listTwo.top();
                listTwo.pop();
            }

            int sum = one + two + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode* node = new ListNode(sum, nextNode);
            nextNode = node;
        }

        return nextNode;
    }
};
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



/* BRUTE FORCE
    class Solution {
    public:
        int countLength(ListNode* head){
            int length = 0;
            ListNode* temp = head;
            while(temp){
                temp = temp->next;
                length++;
            }

            return length;
        }

        int getDecimalValue(ListNode* head) {
            int length = countLength(head) - 1;
            int decimal = 0;
            int power = pow(2, length);

            ListNode* temp = head;
            while(temp){
                decimal += temp->val * power;
                power /= 2;
                temp = temp->next;
            }

            return decimal;
        }
    };
*/

// Better Solution
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal = 0;
        while(head){
            decimal = (decimal * 2) + head->val;
            head = head->next;
        }

        return decimal;
    }
};
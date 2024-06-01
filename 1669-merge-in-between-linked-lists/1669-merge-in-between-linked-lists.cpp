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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list2Head = list2;
        while(list2Head->next){
            list2Head = list2Head->next;
        }
        ListNode* list2Tail = list2Head;

        int count = 0;
        ListNode* list1Head = list1;
        while(count < b){
            count++;
            list1Head = list1Head->next;
            if(count == b){
                list2Tail->next = list1Head->next;
            }
        }

        count = 0;
        list1Head = list1;
        while(count < a){
            count++;
            if(count == a){
                list1Head->next = list2;
            }
            list1Head = list1Head->next;
        }

        return list1;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> hashMap;
        ListNode* tempHead = head;
        while(tempHead){
            if(hashMap.count(tempHead) == 0){
                hashMap[tempHead]++;
            } else {
                return true;
            }
            tempHead = tempHead->next;
        }
        return false;
    }
};
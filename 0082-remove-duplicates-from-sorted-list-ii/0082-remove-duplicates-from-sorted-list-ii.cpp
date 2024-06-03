//
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> hashMap;
        ListNode* tempHead = head;
        while(tempHead){
            hashMap[tempHead->val]++;
            tempHead = tempHead->next;
        }

        ListNode* newHead = new ListNode();
        ListNode* mover = newHead;
        for(auto it : hashMap){
            if(it.second == 1){
                ListNode* newNode = new ListNode(it.first);
                mover->next = newNode;
                mover = mover->next;
            }
        }
        return newHead->next;
    }
};
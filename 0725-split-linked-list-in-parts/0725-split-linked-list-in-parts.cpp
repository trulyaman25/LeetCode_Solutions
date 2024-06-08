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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalLength = 0;
        ListNode* tempHead = head;
        while(tempHead){
            tempHead = tempHead->next;
            totalLength++;
        }

        int remainder = totalLength % k;
        int baseSize = totalLength / k;

        if(totalLength <= k){
            remainder = 0;
            baseSize = 1;
        }

        int count = 0;
        tempHead = head;
        vector<ListNode*> resultVector;

        for (int i = 0; i < k; i++) {
            resultVector.push_back(tempHead);
            int currentSize = baseSize + (i < remainder ? 1 : 0);
            
            for (int j = 1; j < currentSize && tempHead; j++) {
                tempHead = tempHead->next;
            }
            
            if (tempHead) {
                ListNode* nextPart = tempHead->next;
                tempHead->next = nullptr;
                tempHead = nextPart;
            }
        }

        return resultVector;
    }
};
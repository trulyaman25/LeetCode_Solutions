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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tempHead = head->next;

        long long sum = 0;
        vector<long long> resultantVector;
        while(tempHead){
            if(tempHead->val == 0){
                resultantVector.push_back(sum);
                sum = 0;
            } else {
                sum += tempHead->val;
            }
            tempHead = tempHead->next;
        }

        for(auto it : resultantVector){
            cout << it << " ";
        }

        ListNode* newHead = new ListNode(resultantVector[0]);
        ListNode* mover = newHead;
        for(int i = 1; i < resultantVector.size(); i++){
            ListNode* newNode = new ListNode(resultantVector[i]);
            mover->next = newNode;
            mover = mover->next;
        }

        return newHead;
    }
};
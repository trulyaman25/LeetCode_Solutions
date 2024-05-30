//BRUTE FORCE
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, int> hashMap;
//         ListNode* tempHead = head;
//         while(tempHead){
//             if(hashMap.count(tempHead) == 0){
//                 hashMap[tempHead]++;
//             } else {
//                 return true;
//             }
//             tempHead = tempHead->next;
//         }
//         return false;
//     }
// };

//OPTIMIZED SOLUTION USING 2 POINTERS
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer && fastPointer->next){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            
            if(slowPointer == fastPointer){
                return true;
            }
        }

        return false;
    }
};
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ret = nullptr;
        
        while(true){
            if(fast->next == nullptr){
                // odd
                ret = slow;
                break;
            }
            else if(fast->next->next == nullptr){
                // even
                ret = slow->next;
                break;
            }
            else{
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return ret;
    }
};

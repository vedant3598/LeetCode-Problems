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
    ListNode* sortList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        while(p1 != nullptr){
            ListNode* temp = nullptr;
            int currVal = p1->val;
            int lowVal = currVal;
            while(p2 != nullptr){
                if(p2->val < lowVal){
                    temp = p2;
                    lowVal = p2->val;
                }
                p2 = p2->next;
            }
            if(temp != nullptr){
                p1->val = temp->val;
                temp->val = currVal;
            }
            p2 = p1->next;
            p1 = p1->next;
        }
        
        return head;
    }
};

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
        bool cycle = false;
        if(head == nullptr || head->next == nullptr)
            return cycle;
        else{
            ListNode* p1 = head;
            ListNode* p2 = head;
            while(p1 != nullptr && p2 != nullptr){
                p1 = p1->next;
                if(p2->next != nullptr)
                    p2 = p2->next->next;
                else
                    p2 = p2->next;
                if(p1 == p2){
                    return !cycle;
                }
            }
            return cycle;
        }
    }
};

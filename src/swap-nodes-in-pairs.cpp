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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;
        
        while(head != nullptr){
            if(newHead == nullptr){
                if(head->next != nullptr){
                    temp = new ListNode(head->next->val);
                    temp->next = new ListNode(head->val);
                    newHead = temp;
                    temp = temp->next;
                    head = head->next->next;
                }
                else{
                    newHead = head;
                    head = head->next;
                }
            }
            else{
                if(head->next != nullptr){
                    temp->next = new ListNode(head->next->val);
                    temp = temp->next;
                    temp->next = new ListNode(head->val);
                    temp = temp->next;
                    head = head->next->next;
                }
                else{
                    temp->next = new ListNode(head->val);
                    head = head->next;
                }
            }
        }
        return newHead;
    }
};

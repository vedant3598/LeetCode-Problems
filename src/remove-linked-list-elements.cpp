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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = nullptr;
        ListNode* newHead = temp;
  
        while(head != nullptr){
            if(head->val != val){
                if(temp == nullptr){
                    temp = new ListNode(head->val);
                    newHead = temp;
                }
                else{
                    temp->next = new ListNode(head->val);   
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};

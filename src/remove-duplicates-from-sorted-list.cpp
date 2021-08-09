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
    ListNode* deleteDuplicates(ListNode* head) {       
        ListNode* temp = head;
        
        while(temp != nullptr){
            if(temp->next != nullptr && temp->val == temp->next->val){
                ListNode* temp2 = temp;
                while(temp2->next != nullptr && temp2->val == temp2->next->val){
                    temp2 = temp2->next;
                }
                temp->next = temp2->next;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};

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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        ListNode* second = head;
        while(temp != nullptr){
            second = temp;
            temp = temp->next;
            size++;
        }
        
        int counter = 1;
        ListNode* first = head;
        
        if(k == 1 && size > 1){}
        else{
            second = head;
            while(counter != k){
                counter++;
                first = first->next;
            }
            while(size != k){
                size--;
                second = second->next;
            }
        }       
        
        if(size != 1){
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
        return head;
    }
};

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
    int getDecimalValue(ListNode* head) {
        const int binary = 2;
        int dec = 0;
        ListNode* temp = head;
        int size = -1;
        
        
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        
        while(size != -1){
            if(head->val == 1)
                dec += pow(binary, size);
            size--;
            head = head->next;
        }
        return dec;
    }
};

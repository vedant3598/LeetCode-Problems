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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_length = 0;
        int l2_length = 0;
        
        bool l1_larger = false;
        
        ListNode* temp = l1;
        while(temp != nullptr){
            l1_length++;
            temp = temp->next;
        }
        
        temp = l2;
        while(temp != nullptr){
            l2_length++;
            temp = temp->next;
        }
        
        ListNode* head = nullptr;
        ListNode* ret = nullptr;
        ListNode* prev = nullptr;
        if(l2_length == l1_length){
            while(l1 != nullptr){
                if(ret == nullptr){
                    ret = new ListNode(l1->val + l2->val);
                    prev = ret;
                }
                else{
                    int sum = l1->val + l2->val;
                    int num = -1;
                    if(sum > 9)
                        num = sum - 10;
                    
                    if(num >= 0)
                        prev->val += 1;
                    else
                        num = sum;
                    
                    prev->next = new ListNode(num);
                    prev = prev->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return ret;
            
        
        
        
    }
};

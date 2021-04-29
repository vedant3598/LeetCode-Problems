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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        bool carryover = false;
        int sum = 0;
        
        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val;
            
            if(carryover)
                sum += 1;
            
            if(sum > 9){
                sum -= 10;
                carryover = true;
            }
            else{
                carryover = false;
            }
            
            ListNode* newNode = new ListNode(sum);
            if(result == nullptr)
                result = newNode;
            else{
                ListNode* temp = result;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 != nullptr){
            while(l1 != nullptr){
                sum = l1->val;
            
                if(carryover)
                    sum += 1;

                if(sum > 9){
                    sum -= 10;
                    carryover = true;
                }
                else{
                    carryover = false;
                }

                ListNode* newNode = new ListNode(sum);
                ListNode* temp = result;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
                l1 = l1->next;
            }
        }
        
        if(l2 != nullptr){
            while(l2 != nullptr){
                sum = l2->val;
            
                if(carryover)
                    sum += 1;

                if(sum > 9){
                    sum -= 10;
                    carryover = true;
                }
                else{
                    carryover = false;
                }

                ListNode* newNode = new ListNode(sum);
                ListNode* temp = result;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
                l2 = l2->next;
            }
        }
        
        if(carryover){
            ListNode* newNode = new ListNode(1);
            ListNode* temp = result;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        return result;
    }
};

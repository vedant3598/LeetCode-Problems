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
    ListNode* head = nullptr;
    ListNode* lastNode(ListNode* current){
        while(current->next != nullptr){
            current = current->next;
        }
        return current;
    }   
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { 
        if(l1 == nullptr && l2 == nullptr)
            return head;
        else if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        else{}
        
        while(l1 != nullptr && l2 != nullptr){
            if(head == nullptr){
                if(l1->val < l2->val){
                    head = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else if(l1->val > l2->val){
                    head = new ListNode(l2->val);
                    l2 = l2->next;
                }
                else{
                    head = new ListNode(l1->val);
                    head->next = new ListNode(l1->val);
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
            else if(l1->val < l2->val){
                ListNode* temp = new ListNode(l1->val);
                ListNode* current = head;
                current = lastNode(current);
                current->next = temp;
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                ListNode* temp = new ListNode(l2->val);
                ListNode* current = head;
                current = lastNode(current);
                current->next = temp;
                l2 = l2->next;
            }
            else if(l1->val == l2->val){
                ListNode* temp1 = new ListNode(l1->val);
                ListNode* temp2 = new ListNode(l2->val);
                ListNode* current = head;
                current = lastNode(current);
                current->next = temp1;
                current->next->next = new ListNode(l2->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else{}
        }
        
        if(l1 == nullptr && l2 != nullptr){
            ListNode* current = head;
            current = lastNode(current);
            current->next = l2;
        }
        else{
            ListNode* current = head;
            current = lastNode(current);
            current->next = l1;
        }        
        return head;
    }
};

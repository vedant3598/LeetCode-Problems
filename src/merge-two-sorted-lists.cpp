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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        else if(l1 == nullptr && l2 != nullptr)
            return l2;
        else if(l1 != nullptr && l2 == nullptr)
            return l1;
        
        ListNode* ret = nullptr;
        ListNode* temp = nullptr;
        
        if(l1->val > l2->val){
            temp = new ListNode(l2->val);
            l2 = l2->next;
            ret = temp;
        }
        else if(l1->val < l2->val){
            temp = new ListNode(l1->val);
            l1 = l1->next;
            ret = temp;
        }
        else{
            temp = new ListNode(l1->val);
            ret = temp;
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        
        
        while(l1 != nullptr && l2 != nullptr){
            cout << l1->val << " " << l2->val << endl;
            if(l1->val > l2->val){
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if(l1->val < l2->val){
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        if(l1 == nullptr){
            while(l2 != nullptr){
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
                temp = temp->next;
            }
        }
        else{
            while(l1 != nullptr){
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
                temp = temp->next;
            }
        }
        
        return ret;
    }
};

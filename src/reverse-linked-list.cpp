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
    
    ListNode* reverseList(ListNode* head) {
        ListNode* revHead = nullptr;
        int size = 0;
        ListNode* temp = head;
        
        while(temp != nullptr){
            temp = temp->next;
            size++;
        }
       
        temp = head;
        ListNode* temp2 = nullptr;
        while(size != 0){
            while(temp->next != nullptr){
                if(temp->next != nullptr && temp->next->next == nullptr)
                    temp2 = temp;
                temp = temp->next;
            }
            cout << temp->val << endl;
            ListNode* current = new ListNode(temp->val);
            if(revHead == nullptr)
                revHead = current;
            else{
                ListNode* revTemp = revHead;
                while(revTemp->next != nullptr){
                    revTemp = revTemp->next;
                }
                revTemp->next = current;
            }
            if(temp2 != nullptr)
                temp2->next = nullptr;
            
            temp2 = nullptr;
            temp = head;
            size--;
        }
        return revHead;
    }
};

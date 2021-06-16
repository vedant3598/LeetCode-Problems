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
        // Lines 15-26: Converting Linked List into string
        string l1_s = "";
        string l2_s = "";
                
        while(l1 != nullptr){
            l1_s += l1->val;
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            l2_s += l2->val;
            l2 = l2->next;
        }
        
        // Lines 29-71: Starting from the end of the strings, adding the numbers from the strings and putting them in front of the return Linked List
        ListNode* ret = nullptr;
        bool carryOver = false;
        int l1_length = l1_s.length() - 1;
        int l2_length = l2_s.length() - 1;
        int sum = 0;
        
        while(l1_length >= 0 || l2_length >= 0){
            if(ret == nullptr){
                sum = int(l1_s[l1_length]) + int(l2_s[l2_length]);

                if(sum > 9){
                    carryOver = true;  
                    ret = new ListNode(sum - 10);
                }
                else
                    ret = new ListNode(sum);
            }
            else{
                if(l1_length >= 0 && l2_length >= 0)
                    sum = int(l1_s[l1_length]) + int(l2_s[l2_length]);    
                else if(l1_length >= 0)
                    sum = int(l1_s[l1_length]);
                else if(l2_length >= 0)
                    sum = int(l2_s[l2_length]);

                if(carryOver)
                    sum += 1;

                if(sum > 9){
                    carryOver = true;
                    sum -= 10;
                }
                else
                    carryOver = false;

                ListNode* temp = new ListNode(sum);
                temp->next = ret;
                ret = temp;
            }   
            sum = 0;
            l1_length--;
            l2_length--;
        }
        // Lines 73-77: If carryover remains from above, then add that to the front of the Linked List
        if(carryOver){
            ListNode* temp = new ListNode(1);
            temp->next = ret;
            ret = temp;
        }
                
        return ret;        
    }
};

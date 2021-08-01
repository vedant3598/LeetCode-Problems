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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        
        ListNode* newHeadOdd = nullptr;
        ListNode* newHeadEven = nullptr;
        int counter = 1;
        ListNode* odd = nullptr;
        ListNode* even = nullptr;
        
        while(head != nullptr){
            // odd
            if(counter % 2 != 0){
                if(odd == nullptr){
                    odd = new ListNode(head->val);
                    newHeadOdd = odd;
                }
                else{
                    odd->next = new ListNode(head->val);
                    odd = odd->next;
                }
            }
            else{
                if(even == nullptr){
                    even = new ListNode(head->val);
                    newHeadEven = even;
                }
                else{
                    even->next = new ListNode(head->val);
                    even = even->next;
                }
            }
            head = head->next;
            counter++;
        }
        odd->next = newHeadEven;

        return newHeadOdd;
    }
};

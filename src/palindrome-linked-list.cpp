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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        
        stack<int> palindrome;
        ListNode* p1 = head; // moves by 1
        ListNode* p2 = head; // moves by 2
        
        while(true){
            if(p2->next == nullptr){
                // p1 reached halfway (odd palindrome)
                p1 = p1->next;
                break;
            }
            else if(p2->next->next == nullptr){
                // p1 reached halfway (even palindrome)
                palindrome.push(p1->val);
                p1 = p1->next;
                break;
            }
            palindrome.push(p1->val);
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        while(p1 != nullptr){
            if(palindrome.size() != 0 && palindrome.top() == p1->val){
                palindrome.pop();
            }
            p1 = p1->next;
        }
        if(palindrome.size() == 0)
            return true;
        else
            return false;
        
    }
};

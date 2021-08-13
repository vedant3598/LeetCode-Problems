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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int size = 0;
        
        while(current != nullptr){
            ++size;
            current = current->next;
        }
        
        if(size == n){
            head = head->next;
        }
        else{
            ListNode* previous = nullptr;
            current = head;
            while(size != n){
                --size;
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
        }
        return head;
    }
};

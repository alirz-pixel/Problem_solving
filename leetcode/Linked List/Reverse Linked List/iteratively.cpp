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
        ListNode* previous = nullptr;
        ListNode* now_node = head;
        
        while (head != nullptr) {      
            head = head->next;  
            
            now_node->next = previous;
                
            previous = now_node;
            now_node = head;
        }
        
        return previous;
    }
};
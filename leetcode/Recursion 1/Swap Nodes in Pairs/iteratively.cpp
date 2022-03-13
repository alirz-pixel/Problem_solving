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
    ListNode* swapPairs(ListNode* head) {
        if (!head || head->next == nullptr) {
            return head;
        } 
        
        ListNode* new_head = head->next;
        
        while(head && head->next) {
            ListNode* mid_node = head->next;
            ListNode* tail_node = mid_node->next;
            
            mid_node->next = head;
            if (tail_node == nullptr) {
                head->next = tail_node;
                break;
            }
            head->next = tail_node->next;
            
            head = tail_node;
        }
        
        return new_head;
    }
};
// 16분
// https://leetcode.com/explore/featured/card/recursion-i/250/principle-of-recursion/1681/

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
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* connect_next = swapPairs(head->next->next);
        
        ListNode* ret_node = head->next;
        
        head->next->next = head;
        head->next = connect_next;
        
        return ret_node;
    }
};
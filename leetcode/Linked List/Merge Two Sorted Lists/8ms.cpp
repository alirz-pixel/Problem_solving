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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* insert_node;
        ListNode* new_list = nullptr;
        ListNode* tail = nullptr;
        
        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                insert_node = list1;
                list1 = list1->next;
            }
            else {
                insert_node = list2;
                list2 = list2->next;
            }
            
            
            insert_node->next = nullptr;
            if (new_list == nullptr) {
                new_list = insert_node;
                tail = insert_node;
            }
            else {
                tail->next = insert_node;
                tail = tail->next;
            } 
        }
        
        if (new_list == nullptr) {
            if (list1 != nullptr) {
                new_list = list1;
            }
            else {
                new_list = list2;
            }
        }
        else {
            if (list1 != nullptr) {
                tail->next = list1;
            }
            else {
                tail->next = list2;
            }
        }
        
        return new_list;
    };
};
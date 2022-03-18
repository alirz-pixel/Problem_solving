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
        ListNode* new_list = nullptr;
        ListNode* insert_node = nullptr;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                insert_node = list1;
                list1 = list1->next;
                
                push_back(&new_list, &insert_node);
            }
            else {
                insert_node = list2;
                list2 = list2->next;
                
                push_back(&new_list, &insert_node);
            }
        }
        
        while (list1 != nullptr) {
            insert_node = list1;
            list1 = list1->next;
                
            push_back(&new_list, &insert_node);
        }
        
        while (list2 != nullptr) {
            insert_node = list2;
            list2 = list2->next;
                
            push_back(&new_list, &insert_node);
        }
        
        
        return new_list;
    }
    
    void push_back(ListNode** head, ListNode** new_node) {
        (*new_node)->next = nullptr;
        
        if ((*head) == nullptr) {
            (*head) = (*new_node);
        }
        else {
            ListNode* tail = (*head);
            while (tail->next != nullptr) {
                tail = tail->next;
            }    
            
            tail->next = (*new_node);
        }
    }
};
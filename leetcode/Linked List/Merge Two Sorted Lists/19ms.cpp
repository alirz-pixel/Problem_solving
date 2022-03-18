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
        ListNode* tail = nullptr;
        ListNode* insert_node = nullptr;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                insert_node = list1;
                list1 = list1->next;
                
                if (tail == nullptr) {
                    push_back(&new_list, &insert_node);
                    tail = new_list;
                }
                else {
                    cout << insert_node->val << "\n";
                    tail->next = insert_node;
                    tail = tail->next;
                }
            }
            else {
                insert_node = list2;
                list2 = list2->next;
                
                if (tail == nullptr) {
                    push_back(&new_list, &insert_node);
                    tail = new_list;
                }
                else {
                    cout << "insert_node->val" << "\n";
                    tail->next = insert_node;
                    tail = tail->next;
                }
            }
        }
        
        if (tail == nullptr) {
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
// 1CE, 1WA, 1AC, good, but not good enough
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(nullptr == head){
            return head;
        }
        ListNode *ptr, *root;
        ListNode *p1, *p2;
        
        // 1CE here, ListNode(), nt Node()
        root = new ListNode(INT_MIN);
        while(head != nullptr){
            if(root->next == nullptr){
                ptr = head->next;
                root->next = head;
                root->next->next = nullptr;
                head = ptr;
            }else{
                p1 = head->next;
                ptr = root;
                while(ptr->next != nullptr){
                    if(ptr->val <= head->val && ptr->next->val >= head->val){
                        break;
                    }else{
                        ptr = ptr->next;
                    }
                }
                // 1WA here, the case of insertion at tail is ignored 
                p2 = ptr->next;
                ptr->next = head;
                head->next = p2;
                head = p1;
            }
        }
        
        head = root->next;
        delete root;
        return head;
    }
};
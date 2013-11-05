// 1AC, one shot, one kill, YES!!!
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
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *l1, *l2;
        ListNode *r1, *r2;
        
        r1 = new ListNode(0);
        r2 = new ListNode(0);
        
        l1 = r1;
        l2 = r2;
        while(head != nullptr){
            if(head->val < x){
                l1->next = head;
                head = head->next;
                l1 = l1->next;
                l1->next = nullptr;
            }else{
                l2->next = head;
                head = head->next;
                l2 = l2->next;
                l2->next = nullptr;
            }
        }
        l1->next = r2->next;
        head = r1->next;
        delete r1;
        delete r2;
        
        return head;
    }
};
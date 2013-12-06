// 1CE, 2RE, 1AC, why such a hurry... could've 1ac'ed...
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = nullptr, *p2 = nullptr;
        // 1CE here, missing declaration of $i
        int i;
        
        if(nullptr == head) {
            return nullptr;
        }
        
        p1 = head;
        for(i = 0; i < n + 1; ++i) {
            if(p1 == nullptr) {
                break;
            }else {
                p1 = p1->next;
            }
        }
        // 1RE here, i == n, not i == n - 1
        if(i == n) {
            // n == length of the list, valid
            p1 = head;
            head = head->next;
            delete p1;
            // 1RE here, forgot to return head;
            return head;
        }else if(i < n) {
            // n > length of the list, invalid
            return head;
        }else {
            // n < length of the list, valid
            p2 = head;
            while(p1 != nullptr && p2 != nullptr) {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1 = p2->next;
            p2->next = p1->next;
            delete p1;
            return head;
        }
    }
};
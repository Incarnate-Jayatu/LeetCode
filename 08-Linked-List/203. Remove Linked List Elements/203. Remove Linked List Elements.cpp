1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* removeElements(ListNode* head, int val){
14        ListNode* dummy = new ListNode(0);
15        dummy->next = head;
16        ListNode* curr = dummy;
17        while (curr->next != nullptr) {
18            if (curr->next->val == val) {
19                ListNode* toDelete = curr->next;
20                curr->next = curr->next->next; 
21                delete toDelete; 
22            } else {
23                curr = curr->next;
24            }
25        }
26        ListNode* newHead = dummy->next;
27        delete dummy;
28        return newHead;
29    }
30};
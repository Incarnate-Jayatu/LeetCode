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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (!head || !head->next || k == 0) {
15            return head;
16        }
17        int length = 1;
18        ListNode* tail = head;
19        while (tail->next) {
20            tail = tail->next;
21            length++;
22        }
23        k = k % length;
24        if (k == 0) {
25            return head;
26        }
27        tail->next = head;
28        ListNode* newTail = head;
29        for (int i = 0; i < length - k - 1; i++) {
30            newTail = newTail->next;
31        }
32        ListNode* newHead = newTail->next;
33        newTail->next = nullptr;
34        return newHead;
35    }
36};
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
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        ListNode* dummyHead = new ListNode(0);
15        ListNode* tail = dummyHead;
16        int carry = 0;
17        while (l1 != nullptr || l2 != nullptr || carry != 0) {
18            int digit1 = (l1 != nullptr) ? l1->val : 0;
19            int digit2 = (l2 != nullptr) ? l2->val : 0;
20            int sum = digit1 + digit2 + carry;
21            int digit = sum % 10;
22            carry = sum / 10;
23            ListNode* newNode = new ListNode(digit);
24            tail->next = newNode;
25            tail = tail->next;
26            l1 = (l1 != nullptr) ? l1->next : nullptr;
27            l2 = (l2 != nullptr) ? l2->next : nullptr;
28        }
29        ListNode* result = dummyHead->next;
30        delete dummyHead;
31        return result;
32    }
33};
34
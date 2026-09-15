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
13    ListNode* middleNode(ListNode* head) {
14        int totalNodes = 0;
15        ListNode* current = head;
16        while (current != nullptr) {
17            totalNodes++;
18            current = current->next;
19        }
20        int middleIndex = totalNodes / 2;
21        current = head;
22        for (int i = 0; i < middleIndex; ++i) {
23            current = current->next;
24        }      
25        return current;
26    }
27};
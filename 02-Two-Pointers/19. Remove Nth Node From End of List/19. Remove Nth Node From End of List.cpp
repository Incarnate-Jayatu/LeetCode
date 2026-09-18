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
11class Solution{
12public:
13    ListNode* removeNthFromEnd(ListNode* head, int n){
14        ListNode* fast = head;
15        ListNode* slow = head;
16        for(int i = 0; i < n; ++i){
17            fast = fast->next;
18        }
19        if(fast == nullptr){
20            ListNode* newHead = head->next;
21            delete head;
22            return newHead;
23        }
24        while(fast->next != nullptr){
25            fast = fast->next;
26            slow = slow->next;
27        }
28        ListNode* nodeToDelete = slow->next;
29        slow->next = slow->next->next;
30        delete nodeToDelete;
31        return head;
32    }
33};
34
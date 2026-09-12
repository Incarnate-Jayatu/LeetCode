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
12private:
13    ListNode* getMid(ListNode* head) {
14        ListNode* slow = head;
15        ListNode* fast = head->next;
16        while (fast != nullptr && fast->next != nullptr) {
17            slow = slow->next;
18            fast = fast->next->next;
19        }
20        return slow;
21    }
22    ListNode* merge(ListNode* list1, ListNode* list2) {
23        ListNode dummy(0);
24        ListNode* tail = &dummy;
25        while (list1 != nullptr && list2 != nullptr) {
26            if (list1->val < list2->val) {
27                tail->next = list1;
28                list1 = list1->next;
29            } else {
30                tail->next = list2;
31                list2 = list2->next;
32            }
33            tail = tail->next;
34        }
35        tail->next = (list1 != nullptr) ? list1 : list2;
36        return dummy.next;
37    }
38public:
39    ListNode* sortList(ListNode* head) {
40        if (head == nullptr || head->next == nullptr) {
41            return head;
42        }
43        ListNode* mid = getMid(head);
44        ListNode* left = head;
45        ListNode* right = mid->next;
46        mid->next = nullptr;
47        left = sortList(left);
48        right = sortList(right);
49        return merge(left, right);
50    }
51};
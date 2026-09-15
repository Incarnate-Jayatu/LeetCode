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
    ListNode* middleNode(ListNode* head) {
        int totalNodes = 0;
        ListNode* current = head;
        while (current != nullptr) {
            totalNodes++;
            current = current->next;
        }
        int middleIndex = totalNodes / 2;
        current = head;
        for (int i = 0; i < middleIndex; ++i) {
            current = current->next;
        }      
        return current;
    }
};

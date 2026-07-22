#include <numeric>

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list is empty or has only one node, no insertions are needed
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            // Calculate the greatest common divisor of the current and next node's values
            int gcd_val = std::gcd(curr->val, curr->next->val);
            
            // Create the new node with the GCD value
            ListNode* gcd_node = new ListNode(gcd_val);
            
            // Insert the new node between curr and curr->next
            gcd_node->next = curr->next;
            curr->next = gcd_node;
            
            // Move curr to the next original node in the list
            curr = gcd_node->next;
        }
        
        return head;
    }
};
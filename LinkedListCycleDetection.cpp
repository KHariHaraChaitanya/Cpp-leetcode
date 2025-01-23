#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == NULL || head->next == NULL) return false;
        if ((head->next)->next == NULL) return false;

        while (slow != NULL && fast != NULL) {
            slow = slow->next;
            if (fast->next != NULL)
                fast = fast->next->next;
            else
                return false;
            if (fast == slow) {
                std::cout << slow << " - " << fast;
                return true;
            }
        }
        return false;
    }
};

// Helper function to create a linked list with a cycle
ListNode* createLinkedListWithCycle() {
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creates a cycle here
    return head;
}

// Helper function to create a linked list without a cycle
ListNode* createLinkedListWithoutCycle() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    head->next = second;
    return head;
}

int main() {
    Solution solution;

    // Test case 1: Linked list with a cycle
    ListNode* headWithCycle = createLinkedListWithCycle();
    cout << "Test Case 1: " << (solution.hasCycle(headWithCycle) ? "Cycle Detected" : "No Cycle") << endl;

    // Test case 2: Linked list without a cycle
    ListNode* headWithoutCycle = createLinkedListWithoutCycle();
    cout << "Test Case 2: " << (solution.hasCycle(headWithoutCycle) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}

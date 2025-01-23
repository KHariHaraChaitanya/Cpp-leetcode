#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return list1;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;  // Append list1's current node
                list1 = list1->next;
            } else {
                tail->next = list2;  // Append list2's current node
                list2 = list2->next;
            }
            tail = tail->next;  // Move the tail pointer
        }

        // Append the remaining nodes
        tail->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    Solution solution;

    // Create test lists
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});

    // Print input lists
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merge the lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

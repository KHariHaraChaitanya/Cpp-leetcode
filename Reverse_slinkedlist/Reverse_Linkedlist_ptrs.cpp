#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* t1 = head;
        ListNode *t2, *t3;
        if (head == NULL || head->next == NULL)
            return head;

        t2 = t1->next;

        if (t2->next != NULL)
            t3 = t2->next;

        while (t3 != NULL) {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t3->next;
        }

        t2->next = t1;
        head->next = NULL;
        head = t2;

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode* head = createList(arr, size);

    std::cout << "Original List: ";
    printList(head);

    // Reverse the list
    Solution solution;
    head = solution.reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }

    //Find the middle of the linked list
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse the second half of the linked list
    Node *prev = nullptr, *current = slow, *next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Second half is now reversed and `prev` is the head of this half
    Node* secondHalf = prev;

    //Compare the first half and the reversed second half
    Node* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Reverse the second half again to restore the original list
    current = prev;
    prev = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return true;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << "Original list: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    cout << "List after check: ";
    printList(head);

    return 0;
}

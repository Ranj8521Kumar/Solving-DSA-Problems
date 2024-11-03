#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    bool isLengthEven(Node** head) {
        int length = 0;
        Node* temp = *head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        return (length % 2 == 0);
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Solution solution;
    bool result = solution.isLengthEven(&head);
    
    cout << (result ? "Even Length" : "Odd Length") << endl;

    // Cleanup: Free allocated memory for linked list
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    void deleteAlt(Node *head) {
        Node *current = head;
        while (current != nullptr && current->next != nullptr) {
            current->next = current->next->next;
            current = current->next;
        }
    }
};

void insert(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    
    cout << "Original list: ";
    printList(head);

    Solution().deleteAlt(head);
    cout << "Deleted list: ";
    printList(head);

}
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution {
public:
    vector<Node*> alternatingSplitList(struct Node* head) {
        if (head->next == NULL) return {head, NULL};
        if (head->next->next == NULL) {
            Node* head1 = head;
            Node* head2 = head->next;
            head1->next = NULL;
            return {head1, head2};
        }
        Node* head1, *head2, *curr1, *curr2;
        head1 = head;
        head2 = head->next;
        curr1 = head1;
        curr2 = head2;
        while (curr2 && curr2->next) {
            curr1->next = curr2->next;
            curr1 = curr1->next;
            if (curr2->next) {
                curr2->next = curr2->next->next;
                curr2 = curr2->next;
            }
            if (curr2 && curr2->next == NULL) {
                curr1->next = NULL;
            }
        }
        return {head1, head2};
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    vector<Node*> result = solution.alternatingSplitList(head);

    cout << "List 1: ";
    printList(result[0]);

    cout << "List 2: ";
    printList(result[1]);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    int getCount(Node* head) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    Solution solution;
    int count = solution.getCount(head);
    cout << "Number of nodes in the linked list: " << count << endl;

    return 0;
}

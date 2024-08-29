#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class Solution {
public:
    int countNodesinLoop(Node *head) {
        if (!head || !head->next) {
            return 0;
        }
        
        Node *slow = head, *fast = head;
        bool isCycle = false;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        
        if (!isCycle) {
            return 0;
        }
        
        Node *current = slow;
        int lenLoop = 0;
        do {
            current = current->next;
            lenLoop++;
        } while (current != slow);
        
        return lenLoop;
    }
};

int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // Creates a loop
    
    std::cout << "Length of loop: " << sol.countNodesinLoop(head) << std::endl;
    
    return 0;
}

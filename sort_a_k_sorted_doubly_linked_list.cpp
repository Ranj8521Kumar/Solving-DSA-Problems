#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Solution {
  public:
    struct compare {
        bool operator()(DLLNode* a, DLLNode* b) {
            return a->data > b->data;
        }
    };
    
    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        
        priority_queue<DLLNode*, vector<DLLNode*>, compare> minHeap;
        
        DLLNode* newHead = nullptr;
        DLLNode* last = nullptr;
        
        for (int i = 0; i < k + 1 && head != nullptr; i++) {
            minHeap.push(head);
            head = head->next;
        }
        
        while (!minHeap.empty()) {
            DLLNode* minNode = minHeap.top();
            minHeap.pop();
            
            if (newHead == nullptr) {
                newHead = minNode;
                newHead->prev = nullptr;
                last = newHead;
            } else {
                last->next = minNode;
                minNode->prev = last;
                last = minNode;
            }
            
            if (head != nullptr) {
                minHeap.push(head);
                head = head->next;
            }
        }
        
        last->next = nullptr;
        
        return newHead;
    }
};

void printList(DLLNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

DLLNode* appendNode(DLLNode* tail, int data) {
    DLLNode* newNode = new DLLNode(data);
    if (tail != nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
    }
    return newNode;
}

int main() {
    DLLNode* head = new DLLNode(3);
    DLLNode* tail = head;
    tail = appendNode(tail, 6);
    tail = appendNode(tail, 2);
    tail = appendNode(tail, 12);
    tail = appendNode(tail, 56);
    tail = appendNode(tail, 8);
    
    int k = 2;
    
    cout << "Original k-sorted list: ";
    printList(head);
    
    Solution obj;
    DLLNode* sortedHead = obj.sortAKSortedDLL(head, k);
    
    cout << "Sorted list: ";
    printList(sortedHead);
    
    return 0;
}

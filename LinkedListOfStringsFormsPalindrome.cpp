#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    string originalString = "";
    Node* temp = head;
    while (temp) {
        originalString +=           to_string(temp->data);
        temp = temp->next;
    }
    
    string reversedString = originalString;
    reverse(reversedString.begin(), reversedString.end());
    
    return originalString == reversedString;
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

    return 0;
}

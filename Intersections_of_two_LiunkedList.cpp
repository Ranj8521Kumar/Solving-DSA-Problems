#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class Solution {
  private:
    Node* detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        // Use the two-pointer technique to detect a loop
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If pointers meet, a loop is detected
            if(slow == fast) {
                // Move one pointer to head and find the start of the loop
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Starting point of the loop
            }
        }
        
        return nullptr; // No loop detected
    }
    
  public:
    // Function to remove a loop in the linked list
    void removeLoop(Node* head) {
        // Detect the starting point of the loop
        Node* loopStart = detectLoop(head);
        if(loopStart == nullptr) return; // No loop to remove
        
        // Find the last node in the loop
        Node* mover = loopStart;
        while(mover->next != loopStart) {
            mover = mover->next;
        }
        
        // Break the loop
        mover->next = nullptr;
    }
}; 

// class Solution {
// private:
    

// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA == nullptr || headB == nullptr){
//             return nullptr;
//         }

//         int len1 = 0;
//         int len2 = 0;

//         ListNode* tempA = headA;
//         ListNode* tempB = headB;

//         while(tempA){
//             len1++;
//             tempA = tempA->next;
//         }

//         while(tempB){
//             len2++;
//             tempB = tempB->next;
//         }

//         if(len1 > len2){
//             int diff = len1 - len2;
//             while(diff--){
//                 headA = headA->next;
//             }
//         }else{
//             int diff = len2 - len1;
//             while(diff--){
//                 headB = headB->next;
//             }
//         }

//         while(headA){
//             if(headA == headB){
//                 return headA;
//             }
//             headA = headA->next;
//             headB = headB->next;
//         }

//         return nullptr;
//     }
// };

// Function to create a new node
Node* newNode(int key) {
    Node* temp = new Node();
    temp->data = key;
    temp->next = nullptr;
    return temp;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next;
    
    Solution ob;
    ob.removeLoop(head);
    printList(head);
    return 0;
}
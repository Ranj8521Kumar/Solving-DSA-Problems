#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head == nullptr || k==1 || head->next == nullptr){
            return head;
        }
        
        Node* prev = nullptr;
        Node* current = head;
        int count = 0;
        
        while(current != nullptr && count<k){
            Node* nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
            
            count++;
        }
        
        if(current != nullptr){
            head->next = reverseKGroup(current, k);
        }
        
        return prev;
    }
};

void printList(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Solution s;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    int k = 2;
    Node* newHead = s.reverseKGroup(head, k);
    printList(newHead);
    return 0;
}
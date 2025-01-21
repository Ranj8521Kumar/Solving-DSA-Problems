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
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* current = head1; Node* prev = nullptr;
        
        while(current != nullptr && head2 != nullptr){
            if(current->data <= head2->data){
                prev = current;
                current = current->next;
            }else{
                if(prev){
                    prev->next = head2;
                }else{
                    head1 = head2;
                }
                Node* nxtHead2 = head2->next;
                head2->next = current;
                prev = head2;
                head2 = nxtHead2;
            }
        }
        
        if(head2 != nullptr){
            if(prev){
                prev->next = head2;
            }
        }
        
        return head1;
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
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(9);
    
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);
    
    Node* newHead = s.sortedMerge(head1, head2);
    printList(newHead);
    return 0;
}
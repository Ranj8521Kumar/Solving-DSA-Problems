#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasLoop = false;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                hasLoop = true;
                break;
            }
        }
        
        if(!hasLoop){
            return nullptr;
        }

        slow  = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// main function
int main(){
    ListNode* head = new ListNode();
    head->data = 1;
    head->next = new ListNode();
    head->next->data = 2;
    head->next->next = new ListNode();
    head->next->next->data = 3;
    head->next->next->next = new ListNode();
    head->next->next->next->data = 4;
    head->next->next->next->next = head->next;
    
    Solution ob;
    ListNode* res = ob.detectCycle(head);
    if(res){
        cout<<"Loop found";
    }else{
        cout<<"No Loop";
    }
    return 0;
}


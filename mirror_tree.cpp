#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//First Approach
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }
        
        Node* temp = node->right;
        node->right = node->left;
        node->left = temp;
        
        mirror(node->left);
        mirror(node->right);
    }
};

//Second Approach
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        queue<Node*> que;
        que.push(node);
        
        while(!que.empty()){
            int len = que.size();
            vector<Node*> level;
            
            while(len--){
                auto u = que.front();
                que.pop();
                
                level.push_back(u);
                
                if(u->left) que.push(u->left);
                if(u->right) que.push(u->right);
            }
            
            for(auto &u: level){
                swap(u->left, u->right);
            }
        }
    }
};

// Helper function to print the inorder traversal of the binary tree
void inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution sol;
    
    cout << "Inorder traversal of the original tree: ";
    inorder(root);
    cout << endl;
    
    // Converting to mirror tree
    sol.mirror(root);
    
    cout << "Inorder traversal of the mirror tree: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
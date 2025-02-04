#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int solve(Node* root, int &d){
        if(root == nullptr){
            return 0;
        }
        
        int left = solve(root->left, d);
        int right = solve(root->right, d);
        
        d = max(d, left + right);
        
        return 1 + max(left, right);
    }
  
    int diameter(Node* root) {
        int longDiam = 0;
        solve(root, longDiam);
        
        return longDiam;
    }
};

int main() {
    // Create a sample tree: 
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Diameter of the tree is: " << sol.diameter(root) << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
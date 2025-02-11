#include <iostream>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
      bool checkBST(Node* root, int minValue, int maxValue) {
          if (!root) return true;
          
          if (root->data <= minValue || root->data >= maxValue) {
              return false;
          }
          
          return checkBST(root->left, minValue, root->data) && 
                 checkBST(root->right, root->data, maxValue);
      }
  
      bool isBST(Node* root) {
          return checkBST(root, INT_MIN, INT_MAX);
      }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    Solution sol;
    if (sol.isBST(root)) {
        std::cout << "The tree is a BST" << std::endl;
    } else {
        std::cout << "The tree is not a BST" << std::endl;
    }

    return 0;
}
  
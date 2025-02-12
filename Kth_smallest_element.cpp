#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
      void inOrder(Node* root, int k, vector<int>& inOrderArray){
          if(root == nullptr){
              return;
          }
          
          inOrder(root->left, k, inOrderArray);
          inOrderArray.push_back(root->data);
          inOrder(root->right, k, inOrderArray);
      }
      
      // Return the Kth smallest element in the given BST
      int kthSmallest(Node *root, int k) {
          if(root == nullptr){
              return -1;
          }
          
          vector<int> inOrderArray;
          inOrder(root, k, inOrderArray);
          
          if(inOrderArray.size() < k){
              return -1;
          }
          
          return inOrderArray[k-1];
      }
};

int main() {
    // Construct a simple BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution sol;
    int k = 3;
    int result = sol.kthSmallest(root, k);
    if (result != -1) {
        cout << "The " << k << "rd smallest element in the BST is: " << result << endl;
    } else {
        cout << "The BST does not have " << k << " elements." << endl;
    }

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
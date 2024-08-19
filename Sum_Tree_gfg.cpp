#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    pair<bool, int> isSumTreeHelper(Node* node) {
        if (node == nullptr) return {true, 0};
        if (node->left == nullptr && node->right == nullptr) return {true, node->data};
        
        pair<bool, int> left = isSumTreeHelper(node->left);
        pair<bool, int> right = isSumTreeHelper(node->right);
        
        bool isSumTree = (node->data == left.second + right.second);
        
        return {left.first && right.first && isSumTree, node->data + left.second + right.second};
    }
    
    bool isSumTree(Node* root) {
        return isSumTreeHelper(root).first;
    }
};

int main() {
    Solution solution;

    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(2);
    cout << (solution.isSumTree(root1) ? "True" : "False") << endl;

    return 0;
}

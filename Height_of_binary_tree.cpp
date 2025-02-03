#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        if (node == nullptr) return 0;

        int height = 0;
        queue<Node*> que;
        que.push(node);

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                auto u = que.front();
                que.pop();

                if (u->left) que.push(u->left);
                if (u->right) que.push(u->right);
            }

            height++;
        }

        return height;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Height of the binary tree: " << sol.height(root) << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
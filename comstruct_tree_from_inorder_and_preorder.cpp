#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {  // Move Node struct above Solution
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* solve(vector<int> &inorder, vector<int> &preorder, int left, int right, int &preIndex, unordered_map<int, int> &index) {
        if (left > right) {
            return nullptr;
        }

        int rootNode = preorder[preIndex];
        preIndex++;

        int idxRoot = index[rootNode];
        Node *root = new Node(rootNode);

        root->left = solve(inorder, preorder, left, idxRoot - 1, preIndex, index);
        root->right = solve(inorder, preorder, idxRoot + 1, right, preIndex, index);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = preorder.size();
        int preIndex = 0;

        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        return solve(inorder, preorder, 0, n - 1, preIndex, index);
    }
};

void printInorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Solution solution;
    Node* root = solution.buildTree(inorder, preorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

// Definition for binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void convert(Node *head, TreeNode *&root) {
        if (!head) return;

        // Initialize the root of the binary tree with the head of the linked list.
        root = new TreeNode(head->data);
        head = head->next;

        // Queue to store tree nodes and help in constructing the tree level by level.
        queue<TreeNode*> q;
        q.push(root);

        // Iterate through the linked list
        while (head) {
            // Get the current parent node from the queue.
            TreeNode* parent = q.front();
            q.pop();

            // Create the left child if the current node exists.
            if (head) {
                TreeNode* leftChild = new TreeNode(head->data);
                parent->left = leftChild;
                q.push(leftChild);
                head = head->next;
            }

            // Create the right child if the next node exists.
            if (head) {
                TreeNode* rightChild = new TreeNode(head->data);
                parent->right = rightChild;
                q.push(rightChild);
                head = head->next;
            }
        }
    }

    // Utility function to print the level order traversal of the binary tree.
    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
};

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    TreeNode* root1 = nullptr;
    Solution sol;
    sol.convert(head1, root1);
    sol.levelOrderTraversal(root1);

    return 0;
}

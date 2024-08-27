#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void postOrder(Node* root, vector<int>& result) {
    if (root == nullptr) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->data);
}

vector<int> postOrder(Node* root) {
    vector<int> result;
    postOrder(root, result);
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    vector<int> result = postOrder(root);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}

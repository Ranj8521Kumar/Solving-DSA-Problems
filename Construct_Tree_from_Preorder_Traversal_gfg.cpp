#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* constructTreeUtil(int n, int pre[], char preLN[], int& index) {
    if (index >= n) return nullptr;
    Node* root = new Node(pre[index]);
    if (preLN[index] == 'L') {
        index++;
        return root;
    }
    index++;
    root->left = constructTreeUtil(n, pre, preLN, index);
    root->right = constructTreeUtil(n, pre, preLN, index);
    return root;
}

Node* constructTree(int n, int pre[], char preLN[]) {
    int index = 0;
    return constructTreeUtil(n, pre, preLN, index);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n = 5;
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};

    Node* root = constructTree(n, pre, preLN);
    printInorder(root);
    cout << endl;
    return 0;
}

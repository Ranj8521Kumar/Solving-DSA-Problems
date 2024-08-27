#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bstFromPreorderUtil(vector<int>& preorder, int& index, int minValue, int maxValue) {
        int n = preorder.size();
        if (index >= n) return nullptr;

        int value = preorder[index];
        if (value < minValue || value > maxValue) return nullptr;

        index++;
        TreeNode* node = new TreeNode(value);
        node->left = bstFromPreorderUtil(preorder, index, minValue, value);
        node->right = bstFromPreorderUtil(preorder, index, value, maxValue);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderUtil(preorder, index, INT_MIN, INT_MAX);
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = sol.bstFromPreorder(preorder);
    printInorder(root);
    cout << endl;
    return 0;
}

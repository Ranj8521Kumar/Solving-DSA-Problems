#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> que;
        que.push(root);

        int count = 0;

        while (!que.empty()) {
            int len = que.size(); //size of the current level

            vector<int> currentLevel;
            for (int i = 0; i < len; i++) {
                TreeNode* node = que.front();
                que.pop();

                currentLevel.push_back(node->val);

                //creating next level if it exists
                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }

            vector<int> sorted(currentLevel.begin(), currentLevel.end());
            sort(sorted.begin(), sorted.end());
            unordered_map<int, int> mpp; //mapping of the sorted array {element, index}
            for (int i = 0; i < len; i++) {
                mpp[sorted[i]] = i;
            }

            for (int i = 0; i < len; ) {
                int rightIndex = mpp[currentLevel[i]];
                if (rightIndex != i) {
                    swap(currentLevel[rightIndex], currentLevel[i]); 
                    count++;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    int result = sol.minimumOperations(root);
    cout << "Minimum operations to sort binary tree by level: " << result << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val= val;
        this->left = nullptr;
        this->right = nullptr;

    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level = 0; // Start from the root level
        
        while (!que.empty()) {
            vector<TreeNode*> currentLevel; // Nodes at the current level
            int len = que.size(); // Number of nodes in the current level
            
            // Process all nodes at this level
            while (len--) {
                TreeNode* node = que.front();
                que.pop();
                currentLevel.push_back(node);
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            
            // Reverse values for alternate levels
            if (level % 2 != 0) {
                int left = 0, right = currentLevel.size() - 1;
                while (left < right) {
                    swap(currentLevel[left]->val, currentLevel[right]->val);
                    left++;
                    right--;
                }
            }
            level++; // Move to the next level
        }

        return root;
    }
};


//using dfs and recursion
class Solution {
public:
    void solve(TreeNode* Left, TreeNode* Right, int level){
        if(Left == nullptr){
            return;
        }

        if(Right == nullptr){
            return;
        }

        if(level % 2 != 0){
            swap(Left->val, Right->val);
        }

        solve(Left->left, Right->right, level+1);
        solve(Left->right, Right->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1);

        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* newRoot = sol.reverseOddLevels(root);

    queue<TreeNode*> que;
    que.push(newRoot);
    while (!que.empty()) {
        TreeNode* node = que.front();
        que.pop();
        cout << node->val << " ";
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
    }

    return 0;
}
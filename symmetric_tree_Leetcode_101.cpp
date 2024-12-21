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
    bool solve(TreeNode* l, TreeNode* r){
        if(l == nullptr && r ==  nullptr){
            return true;
        }
        if(l == nullptr || r == nullptr){
            return false;
        }

        if(l->val !=  r->val){
            return false;
        }

        return solve(l->left, r->right) && solve(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;
    cout<<obj.isSymmetric(root)<<endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        
        if(root != nullptr){
            que.push(root);
        }

        while(!que.empty()){
            int len = que.size();
            int maxElem = INT_MIN;

            while(len--){
                auto u = que.front();
                que.pop();
                maxElem = max(maxElem, u->val);

                if(u->left){
                    que.push(u->left);
                }

                if(u->right){
                    que.push(u->right);
                }
            }

            result.push_back(maxElem);
        }

        return result;
    }
};


//second code
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        //level order traversal or BFS
        vector<int> result;
        queue<TreeNode*> que;
        
        if(root != nullptr){
            que.push(root);
        }

        while(!que.empty()){
            int len = que.size();

            vector<int> level;
            while(len--){
                auto u = que.front();
                que.pop();
                level.push_back(u->val);

                //push node of next level in the queue
                if(u->left){
                    que.push(u->left);
                }

                if(u->right){
                    que.push(u->right);
                }
            }

            int maxElem = INT_MIN;
            for(auto &it: level){
                maxElem = max(maxElem, it);
            }

            result.push_back(maxElem);
        }

        return result;
    }
};

//second approach
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
    //DFS Approach

    void DFS(TreeNode* root, int depth, vector<int>& result){
        if(root == nullptr){
            return;
        }

        if(result.size() == depth){//first time visit to that depth
            result.push_back(root->val); 
        }else{//already visited to that depth
            result[depth] = max(result[depth], root->val);
        }

        if(root->left){
            DFS(root->left, depth+1, result);
        }

        if(root->right){
            DFS(root->right, depth+1, result);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> result;

        DFS(root, 0, result);// 0  -> current depth

        return result;
    }
};

int main() {
    // Create a sample tree: 
    //       1
    //      / \
    //     3   2
    //    / \   \  
    //   5   3   9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    vector<int> result = sol.largestValues(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
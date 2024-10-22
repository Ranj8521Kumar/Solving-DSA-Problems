#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<long long, vector<long long>, greater<long long>> sumQueue;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            while (size > 0) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                size--;
            }
            sumQueue.push(sum);
            if (sumQueue.size() > k) sumQueue.pop();
        }
        return sumQueue.size() < k ? -1 : sumQueue.top();
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution solution;
    int k = 2;
    cout << solution.kthLargestLevelSum(root, k) << endl;

    return 0;
}

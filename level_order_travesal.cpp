#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            int n = que.size();
            vector<int> currentRow;
            
            for(int i = 0; i < n; i++){
                auto u = que.front();
                que.pop();
                
                currentRow.push_back(u->data);
                
                if(u->left) que.push(u->left);
                if(u->right) que.push(u->right);
            }
            
            result.push_back(currentRow);
        }
        
        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
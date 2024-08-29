#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    vector<Node*> children;

    Node(){}

    Node(int _val){
        val = _val;
    }

    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

class Solution{
    public:
    vector<int> postorder(Node* root){
        vector<int> result;
        if(root == nullptr) return result;
        traverse(root, result);
        return result;
    }


    void traverse(Node* node, vector<int>& result){
        for(Node* child : node->children){
            traverse(child, result);
        }
        result.push_back(node->val);
    }
};

int main() {
    Node* child1 = new Node(5);
    Node* child2 = new Node(6);
    vector<Node*> children1 = {child1, child2};
    Node* node1 = new Node(3, children1);

    Node* node2 = new Node(2);
    Node* node3 = new Node(4);
    
    vector<Node*> children0 = {node1, node2, node3};
    Node* root = new Node(1, children0);

    Solution obj;
    vector<int> result = obj.postorder(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete child1;
    delete child2;

    return 0;
}
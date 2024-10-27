#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        return root;
    }
};
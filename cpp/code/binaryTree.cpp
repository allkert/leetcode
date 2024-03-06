# include<iostream>
# include<string>
# include<algorithm>
# include<limits>
# include<queue>
# include<vector>
# include<stack>
# include<list>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};
class Solution{
public:
    // 144. 二叉树的前序遍历
    // 递归
    void preTraversal(TreeNode *node, vector<int>& res){
        if(node == nullptr) return;
        res.push_back(node->val);
        preTraversal(node->left, res);
        preTraversal(node->right, res);
    }
    vector<int> preorderTraversal_recursion(TreeNode* root) {
        vector<int> res;
        preTraversal(root, res);
        return res;
    }

    // 迭代
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> res;
        stack<TreeNode> st;
        
    }

    // 94.二叉树的中序遍历
    // 递归
    void inorderTraversal(TreeNode *Node, vector<int>& res){
        if(Node == NULL) return;
        inorderTraversal(Node->left, res);
        res.push_back(Node->val);
        inorderTraversal(Node->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }

    // 145.二叉树的后序遍历
    // 递归
    void postTraversal(TreeNode* cur, vector<int>& res){
        if(!cur) return;
        postTraversal(cur->left, res);
        postTraversal(cur->right, res);
        res.push_back(cur->val);
    }

    vector<int> postorderTraversal_recursion(TreeNode *root){
        vector<int> res;
        postTraversal(root, res);
        return res;
    }
};

int main(){
    vector<int> a = {1,2,3};
    stack<int, list<int>> b{1,2,3,4};
}
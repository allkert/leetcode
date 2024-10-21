/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <algorithm>
#include <stack>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void preorderTraverseRecursion(TreeNode* root, vector<int>& order) {
        if (root == nullptr) return;
        order.push_back(root->val);
        preorderTraverseRecursion(root->left, order);
        preorderTraverseRecursion(root->right, order);
    }
    void inorderTraverseRecursion(TreeNode* root, vector<int>& order) {
        if (root == nullptr) return;
        inorderTraverseRecursion(root->left, order);
        order.push_back(root->val);
        inorderTraverseRecursion(root->right, order);
    }
    void postorderTraverseRecursion(TreeNode* root, vector<int>& order) {
        if (root == nullptr) return;
        postorderTraverseRecursion(root->left, order);
        postorderTraverseRecursion(root->right, order);
        order.push_back(root->val);
    }
    void preorderTraversal(TreeNode* root, vector<int>& order){
        if(root == nullptr) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto cur = st.top(); st.pop();
            order.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
    }
    void inorderTraversal(TreeNode* root, vector<int>& order){
        stack<TreeNode*> st;
        auto cur = root;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top(); st.pop();
                order.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    void postorderTraversal(TreeNode* root, vector<int>& order){
        if(!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto cur = st.top(); st.pop();
            order.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(order.begin(), order.end());
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<int> preorder, inorder, postorder;
        vector<vector<int>> res;
        preorderTraversal(root, preorder);
        inorderTraversal(root, inorder);
        postorderTraversal(root, postorder);
        res.push_back(preorder);
        res.push_back(inorder);
        res.push_back(postorder);
        return res;
    }
};
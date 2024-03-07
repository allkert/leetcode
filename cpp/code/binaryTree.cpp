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
        if(!root) return {};
        vector<int> res;
        stack<TreeNode> st;
        st.push(*root);
        while(!st.empty()){
            TreeNode node = st.top();
            res.push_back(node.val);
            st.pop();
            if(node.right != NULL){
                st.push(*node.right);
            }
            if(node.left != NULL){
                st.push(*node.left);
            }
        }
        return res;
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

    // 迭代
    vector<int> postorderTraversal(TreeNode *root){
        if(root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(!st.empty() or cur != NULL){
            if(cur == NULL){
                cur = st.top();
                res.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
            else{
                st.push(cur);
                cur = cur->left;
            }
            
        }
        return res;
    }

    // 迭代
    // 先中右左遍历，然后反过来
    vector<int> postorderTraversal(TreeNode *root){
        if(root == NULL) return {};
        vector<int> res;
        stack<TreeNode> st;
        st.push(*root);
        while (!st.empty()){
            TreeNode node = st.top();
            st.pop();
            res.push_back(node.val);
            if(node.left){
                st.push(*node.left);
            }
            if(node.right){
                st.push(*node.right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }

    // 前中后序遍历的统一写法
    // 以中序遍历为例
    vector<int> generalTrversal(TreeNode *root){
        vector<int> res;
        stack<TreeNode*> st;
        if(root == NULL) return {};
        st.push(root);
        while(!st.empty()){
            TreeNode* nodeptr = st.top();
            st.pop();
            if(nodeptr != NULL){
                if(nodeptr->right){
                    st.push(nodeptr->right);
                }
                st.push(nodeptr);
                st.push(NULL);
                if(nodeptr->left){
                    st.push(nodeptr->left);
                }
            }
            else{
                nodeptr = st.top();
                st.pop();
                res.push_back(nodeptr->val);
            }
        }
        return res;
    }


    // 102 二叉树的层序遍历
    // 迭代法
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode> layer;
        vector<vector<int>> res;
        if(root == NULL) return res;
        layer.push(*root);
        while(!layer.empty()){
            vector<int> layerval;
            int size = layer.size();
            for(int i = 0; i < size; i++){
                TreeNode node = layer.front();
                layer.pop();
                layerval.push_back(node.val);
                if(node.left){
                    layer.push(*node.left);
                }
                if(node.right){
                    layer.push(*node.right);
                }
            }
            res.push_back(layerval);
        }
        return res;
    }

    // 递归法
    vector<vector<int>> levelOrder_recursion(TreeNode *root){
        vector<vector<int>> res;
        order(root, res, 0);
        return res;
    }
    void order(TreeNode *nodeptr, vector<vector<int>>& res, int depth){
        if(nodeptr == NULL) return;
        // 为当前depth开辟一个vector<int>空间
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(nodeptr->val);
        // 这里必须先左后右
        order(nodeptr->left, res, depth+1);
        order(nodeptr->right, res, depth+1);
    }

    // 107 二叉树的层序遍历2
    void levelOrder_reverse_recursion(vector<vector<int>>& res, TreeNode *curptr, int depth){
        if(curptr == NULL) return;
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(curptr->val);
        levelOrder_reverse_recursion(res, curptr->left, depth+1);
        levelOrder_reverse_recursion(res, curptr->right, depth+1);
    }

    vector<vector<int>> levelOrder_reverse(TreeNode *root){
        vector<vector<int>> res;
        levelOrder_reverse_recursion(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
    }

    // 199. 二叉树的右视图
    void rightSideView_recursion(TreeNode *nodeptr, vector<int>& res, int depth){
        if(nodeptr == NULL) return;
        if(res.size() == depth){
            res.push_back(nodeptr->val);
        }
        else{
            res[depth] = nodeptr->val;
        }
        rightSideView_recursion(nodeptr->left, res, depth+1);
        rightSideView_recursion(nodeptr->right, res, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSideView_recursion(root, res, 0);
        return res;
    }

    // 637. 二叉树的层平均值
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode>  queue;
        if(root == NULL) return {};
        queue.push(*root);
        while(!queue.empty()){
            double sum = 0;
            int nodenum = 0;
            int layersize = queue.size();
            for(;nodenum < layersize; nodenum++){
                TreeNode tmp = queue.front();
                queue.pop();
                sum += tmp.val;
                if(tmp.left) queue.push(*tmp.left);
                if(tmp.right) queue.push(*tmp.right);
            }
            res.push_back(sum/nodenum);
        }
    return res;
    }


    // 429. N叉树的层序遍历
    // 迭代
    vector<vector<int>> levelOrder_Ntrees(Node* root) {
        vector<vector<int>> res;
        queue<Node> queue;
        if(root != NULL) queue.push(*root);
        while(!queue.empty()){
            int nodenum = queue.size();
            vector<int> layer_traversal;
            for(int i = 0; i < nodenum; i++){
                Node node = queue.front();
                queue.pop();
                layer_traversal.push_back(node.val);
                for(Node* n : node.children){
                    queue.push(*n);
                }
            }
            res.push_back(layer_traversal);
        }
        return res;
    }

};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int main(){
    vector<int> a = {1,2,3};
}
# include<iostream>
# include<limits>
# include<algorithm>
# include<math.h>
#include <vector>
#include <stack>

using namespace std;

/* 
    用于记录没学会的题复习

*/


struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};

class Solution{
public:
    /* 1. 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 */
    // 代码随想录的解法
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while(left){
            left = left->left;
            leftDepth++;
        }
        while(right){
            right = right->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth){
            return (2 << leftDepth) - 1; 
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    // 二分查找 + 位运算
    // 背一下plz
    int countNodes1(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int level = 1;
        TreeNode* node = root;

        // 求得二叉树的最大深度为level
        while(node->left != NULL){
            level++;
            node = node->left;
        }

        int low = 1<<(level-1), high = (1<<level)-1;

        // 二分查找
        while(low < high){
            int mid = (low+high+1)/2;
            if(existNode(root, level, mid)){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }

    bool existNode(TreeNode* root, int level, int k){
        int bits = 1 << (level-2);
        while(root != NULL && bits > 0){
            if((bits&k) != 0){
                root = root->right;
            }
            else{
                root = root->left;
            }
            bits = bits >> 1;
        }
        return root != NULL;
    }


    // 110.判断平衡二叉树
    // 判断是否为平衡二叉树，如果是返回高度，否则返回-1
    // 递归
    int getHeight(TreeNode *node){
        if(node == NULL){
            return 0;
        }
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }


    bool isBalanced(TreeNode* root) {
        int res = getHeight(root);
        return res == -1? false:true;
    }

        // 501 二叉搜索树中的众数
    // 迭代
    vector<int> findMode_it(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        int count = 0;
        int maxcount = 0;
        stack<TreeNode*> st;
        vector<int> res;
        while(!st.empty() or cur != NULL){
            if(cur == NULL){
                cur =st.top();st.pop();
                if(pre == NULL) count = 1;
                else if(pre->val == cur->val) count++;
                else count = 1;
                if(count == maxcount) res.push_back(cur->val);
                if(count > maxcount){
                    maxcount = count;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right; 
            }
            else{
                st.push(cur);
                cur = cur->left;
            }
            
        }
        return res;
    }
};
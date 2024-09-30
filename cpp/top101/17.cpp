
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param inorder int整型vector 中序遍历序列
     * @param postorder int整型vector 后序遍历序列
     * @return TreeNode类
     */

    TreeNode* buildT(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2){
        if(l1 > r1) return nullptr;
        auto root = new TreeNode(postorder[r2]);
        int index;
        for(int i = l1; i <= r1; i++){
            if(inorder[i] == root->val){
                index = i;
                break;
            }
        }
        root->left = buildT(inorder, postorder, l1, index - 1, l2, l2 + index - l1 - 1);
        root->right = buildT(inorder, postorder, index + 1, r1, l2 + index - l1, r2 - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // write code here
        auto root = buildT(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
};
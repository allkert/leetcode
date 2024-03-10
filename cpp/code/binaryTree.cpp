# include<iostream>
# include<string>
# include<algorithm>
# include<limits>
# include<queue>
# include<vector>
# include<stack>
# include<list>

using namespace std;

void printvector(vector<int> v){
    for(int num: v){
        cout << num << '\t';
    }
    cout << endl;
}

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class NtreeNode {
public:
    int val;
    vector<NtreeNode*> children;

    NtreeNode() {}

    NtreeNode(int _val) {
        val = _val;
    }

    NtreeNode(int _val, vector<NtreeNode*> _children) {
        val = _val;
        children = _children;
    }
};

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
    void inorderT(TreeNode *Node, vector<int>& res){
        if(Node == NULL) return;
        inorderT(Node->left, res);
        res.push_back(Node->val);
        inorderT(Node->right, res);
    }
    vector<int> inorderTraversal_recursion(TreeNode* root) {
        vector<int> res;
        inorderT(root, res);
        return res;
    }

    // 迭代
    vector<int> inorderTraversal_it(TreeNode *root){
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
    vector<vector<int>> levelOrder_Ntrees(NtreeNode* root) {
        vector<vector<int>> res;
        queue<NtreeNode> queue;
        if(root != NULL) queue.push(*root);
        while(!queue.empty()){
            int nodenum = queue.size();
            vector<int> layer_traversal;
            for(int i = 0; i < nodenum; i++){
                NtreeNode node = queue.front();
                queue.pop();
                layer_traversal.push_back(node.val);
                for(NtreeNode* n : node.children){
                    queue.push(*n);
                }
            }
            res.push_back(layer_traversal);
        }
        return res;
    }

    // 递归
    void Ntrees_recursion(vector<vector<int>>& res, int depth, NtreeNode* root){
        if(root == NULL) return;
        if(res.size() == depth){
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        for(NtreeNode* child: root->children){
            Ntrees_recursion(res, depth+1, child);
        }
    }
    vector<vector<int>> levelOrder_Ntrees_recursion(NtreeNode* root){
        vector<vector<int>> res;
        Ntrees_recursion(res, 0, root);
        return res;
    }


    // 515 在每个树行中找最大值
    // 迭代
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode> queue;
        if(root != NULL) queue.push(*root);
        while(!queue.empty()){
            int nodenum = queue.size();
            int max_ = INT_MIN;
            for(int i = 0; i < nodenum; i++){
                TreeNode tmp = queue.front();
                queue.pop();
                max_ = max_ > tmp.val? max_:tmp.val;
                if(tmp.left) queue.push(*tmp.left);
                if(tmp.right) queue.push(*tmp.right);
            }
            res.push_back(max_);
        }
        return res;
    }

    // 递归
    vector<int> largestValues_recursion(TreeNode* root){
        vector<int> res;
        largestV_recursion(res, 0, root);
        return res;
    }

    void largestV_recursion(vector<int>& res, int depth, TreeNode *root){
        if (root == NULL) return;
        if(res.size() == depth){
            res.push_back(root->val);
        }
        else{
            res[depth] = res[depth] > root->val? res[depth]:root->val;
        }
        largestV_recursion(res, depth+1, root->left);
        largestV_recursion(res, depth+1, root->right);
    }


    // 116. 填充每个节点的下一个右侧节点指针
    // 117. 填充每个节点的下一个右侧节点指针 II
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                Node *tmp = queue.front();
                queue.pop();
                if(tmp->left) queue.push(tmp->left);
                if(tmp->right) queue.push(tmp->right);
                if(i != size - 1){
                    tmp->next = queue.front();
                }
            }
        }
        return root;
    }


    // 117. 填充每个节点的next指针，指向下一个右节点。
    Node* connect2(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            stack<Node*> st;
            for(int i = 0; i < size; i++){
                Node* ptr = queue.front();
                queue.pop();
                if(ptr == nullptr){
                    ptr = queue.front();
                    queue.pop();
                    i++;
                    while(!st.empty()){
                        st.top()->next = ptr;
                        st.pop();
                    }
                }
                st.push(ptr);
                if(ptr->left) queue.push(ptr->left);
                if(ptr->right){
                    queue.push(nullptr);
                    queue.push(ptr->right);
                }
            }
        }
        return root;
    }


    // 104 二叉树的最大深度
    // 递归
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1+ max(maxDepth(root->left), maxDepth(root->right));    
    }

    // 不行我要用迭代，递归太简单了
    // nonono，迭代也很简单，层序遍历，不愧是简单题，真不行啊

    
    // 111. 二叉树的最小深度
    // 递归
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftMinDepth = minDepth(root->left);
        int rightMinDepth = minDepth(root->right);
        if(leftMinDepth == 0 && rightMinDepth == 0){
            return 1;
        }
        else{
            if(leftMinDepth == 0){
                return 1 + rightMinDepth;
            }
            else if(rightMinDepth == 0){
                return 1 + leftMinDepth;
            }
            else{
                return 1 + min(leftMinDepth, rightMinDepth);
            }
        }
    }

    // 迭代
    int minDepth_it(TreeNode* root){
        if(root == NULL) return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int depth = 1;
        for( ; !queue.empty(); depth++){
            int len = queue.size();
            for(int i = 0; i < len; i++){
                TreeNode* tmp = queue.front();
                queue.pop();
                if(tmp->left == NULL and tmp->right == NULL){
                    return depth;
                }
                if(tmp->left){
                    queue.push(tmp->left);
                }
                if(tmp->right){
                    queue.push(tmp->right);
                }
            }
        }
        return depth;
        
    }

    // 226  翻转二叉树
    void invertT_recursion(TreeNode *root){
        if(root == NULL) return;
        swap(root->left, root->right);
        invertT_recursion(root->left);
        invertT_recursion(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertT_recursion(root);
        return root;
    }

    //101 对称二叉树
    // 递归
    bool compare(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL or right == NULL) return false;
        if(left->val != right->val) return false;
        return (compare(left->left, right->right) && compare(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return compare(root->left, root->right);
    }
    
    // 迭代
    bool isSymmetric_it(TreeNode* root){
        if(root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode* node1 = st.top();st.pop();
            TreeNode* node2 = st.top();st.pop();
            if(node1 == NULL && node2 == NULL) continue;
            if((node1 == NULL && node2 != NULL) ||
               (node1 != NULL && node2 == NULL) ||
               (node1->val != node2->val)){
                return false;
            }
            st.push(node1->left);
            st.push(node2->right);
            st.push(node1->right);
            st.push(node2->left);
        }
        return true;
    }

    // 222.完全二叉树的节点数
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

    // 257.二叉树的所有路径
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<string>> res_;
        vector<string> res;
        backtracking_bingaryTreePaths(res_, root, vector<string>());
        for(vector<vector<string>>:: iterator it1 = res_.begin(); it1 != res_.end(); it1++){
            string tmp;
            vector<string>:: iterator it2 = (*it1).begin();
            for(; it2 != (*it1).end()-1; it2++){
                tmp += *it2;
                tmp += "->";
            }
            tmp+=*it2;
            res.push_back(tmp);
        }
        return res;
    }

    void backtracking_bingaryTreePaths(vector<vector<string>>& res, TreeNode *node, vector<string> path){
        if(node == NULL) return;
        path.push_back(to_string(node->val));
        if(node->left == NULL and node->right == NULL){
            res.push_back(path);
        }
        else{
            backtracking_bingaryTreePaths(res, node->left, path);
            backtracking_bingaryTreePaths(res, node->right, path);
        }
    }

    vector<string> binaryTreePaths_ref(TreeNode* root) {
        vector<string> res;
        if(root != NULL){
            backtracking_binaryTreePaths_ref(root, "", res);
        }
        return res;
    }

    void backtracking_binaryTreePaths_ref(TreeNode *node, string path, vector<string>& res){
        path += to_string(node->val);
        if(node->left == NULL && node->right==NULL){
            res.push_back(path);
        }
        else{
            if(node->left){
                backtracking_binaryTreePaths_ref(node->left, path + "->", res);
            }
            if(node->right){
                backtracking_binaryTreePaths_ref(node->right, path + "->", res);
            }
        }
    }


    // 404 左叶子之和
    int sumOfLeftLeaves_my(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left != NULL){
            if(root->left->left == NULL && root->left->right == NULL){
                return root->left->val + sumOfLeftLeaves_my(root->right);
            } 
            else{
                return sumOfLeftLeaves_my(root->left) + sumOfLeftLeaves_my(root->right);
            }

        }
        else{
            return sumOfLeftLeaves_my(root->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root){
        if(root == NULL) return 0;
        int leftValue = 0;
        if (root->left && !root->left->left && !root->left->right) { // 左子树就是一个左叶子的情况
            leftValue = root->left->val;
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + leftValue;
    }

    // 迭代
    int sumOfLeftLeaves_it(TreeNode* root){
        stack<TreeNode*> st;
        if(root == NULL) return 0;
        st.push(root);
        int result = 0;
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
                result += node->left->val;
            }
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return result;
    }


    // 513找树左下角的值
    // 迭代
    int findBottomLeftValue_it(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res;
        while(!q.empty()){
            int size = q.size();
            res = q.front()->val;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }

    // 递归
    int findBottomLeftValue(TreeNode* root) {
        int resdepth = -1;
        int res;
        findBottomLeftV_recursion(root, 0, res, resdepth);
        return res;
    }

    void findBottomLeftV_recursion(TreeNode* root, int curdepth, int& res, int& resdepth){
        if(root->left == NULL and root->right == NULL){
            if(curdepth > resdepth){
                resdepth = curdepth;
                res = root->val;
            }
            return;
        }
        if(root->left) findBottomLeftV_recursion(root->left, curdepth+1, res, resdepth);
        if(root->right) findBottomLeftV_recursion(root->right, curdepth+1, res, resdepth);
    }


    // 112.路径总和
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL){
            if(root->val == targetSum) return true;
            return false;
        }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }

    // 106. 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree_r_in_post(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        int midval = *postorder.rbegin();
        int index;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == midval){
                index = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(midval);
        vector<int> inorderLeft = getSub(inorder, 0, index);
        vector<int> inorderRight= getSub(inorder, index+1,inorder.size());
        vector<int> postorderLeft = getSub(postorder, 0, index);
        vector<int> postorderRight = getSub(postorder, index, postorder.size()-1);
        node->left = buildTree_r_in_post(inorderLeft, postorderLeft);
        node->right = buildTree_r_in_post(inorderRight, postorderRight);
        return node;
    }

    vector<int> getSub(vector<int> origin, int start, int end){
        vector<int> res;
        for(int i = start; i < end; i++){
            res.push_back(origin[i]);
        }
        return res;
    }

    // 这种写法占用空间很大，因为在函数中创建了int容器
    TreeNode* traversalBuildTree_in_post_ref(vector<int>& inorder, vector<int>& postorder, int inorderbegin, int inorderend, int postorderbegin, int postorderend){
        if(inorderbegin == inorderend) return NULL;
        int rootval = postorder[postorderend-1];
        TreeNode* node = new TreeNode(rootval);
        int index = inorderbegin;
        for(; index < inorderend; index++){
            if(inorder[index] == rootval){
                break;
            }
        }
        node->left  = traversalBuildTree_in_post_ref(inorder, postorder, inorderbegin, index, postorderbegin, postorderbegin + index - inorderbegin);
        node->right = traversalBuildTree_in_post_ref(inorder, postorder, index+1, inorderend, postorderbegin + index - inorderbegin, postorderend-1);
        return node;
    }

    TreeNode* buildTree_in_post_ref(vector<int>& inorder, vector<int>& postorder){
        return traversalBuildTree_in_post_ref(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }


    // 105. 从前序与中序遍历序列构造二叉树
    TreeNode* buildTree_pre_in_traversal(vector<int> preorder, vector<int> inorder, int inorderBegin, int inorderEnd, int preorderBegin, int preorderEnd){
        if(inorderBegin == inorderEnd) return NULL;
        int rootVal = preorder[preorderBegin];
        int index = inorderBegin;
        for(; index < inorderEnd; index++){
            if(inorder[index] == rootVal) break;
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left  = buildTree_pre_in_traversal(preorder, inorder, inorderBegin, index, preorderBegin+1, preorderBegin+1+index-inorderBegin);
        root->right = buildTree_pre_in_traversal(preorder, inorder, index+1, inorderEnd, preorderBegin+1+index-inorderBegin, preorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_pre_in_traversal(preorder, inorder, 0, inorder.size(), 0, preorder.size());
    }

    // 最大二叉树
    TreeNode* constructMaximumBinaryTree_Traversal(vector<int>& nums, int begin, int end){
        if(begin == end) return nullptr;
        int max_ = INT_MIN;
        int maxIndex = -1;
        // find the max
        for(int i = begin; i < end; i++){
            if(nums[i]>max_){
                max_ = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode(max_);
        root->left  = constructMaximumBinaryTree_Traversal(nums, begin, maxIndex);
        root->right = constructMaximumBinaryTree_Traversal(nums, maxIndex+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree_Traversal(nums, 0, nums.size());
    }


    // 617 合并二叉树
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return NULL;
        if(root1 != NULL && root2 != NULL){
            root2->val += root1->val;
            root2->left = mergeTrees(root1->left, root2->left);
            root2->right = mergeTrees(root1->right, root2->right);
            return root2;
        }
        if(root1 == NULL && root2 != NULL) return root2;
        else return root1;
    }

    // 迭代解法
    TreeNode* mergeTrees_it(TreeNode* root1, TreeNode *root2){
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while(!que.empty()){
            TreeNode* node1 = que.front();que.pop();
            TreeNode* node2 = que.front();que.pop();
            node1->val += node2->val;
            if(node1->left != NULL && node2->left != NULL){
                que.push(node1->left);
                que.push(node2->left);
            }
            if(node1->right != NULL && node2->right != NULL){
                que.push(node1->right);
                que.push(node2->right);
            }

            if(node1->left == NULL && node2->left != NULL){
                node1->left = node2->left;
            }

            if(node1->right == NULL && node2->right != NULL){
                node1->right = node2->right;
            }
            
        }
        return root1;
    }


    // 700 二叉搜索树中的搜索 
    // 迭代
    TreeNode* searchBST_it(TreeNode* root, int val) {
        TreeNode *cur = root;
        while(cur != NULL){
            if(cur->val == val) return cur;
            else if(val > cur->val) cur = cur->right;
            else cur = cur->left;
        }
        return NULL;
    }

    TreeNode* searchBST(TreeNode* root, int val){
        if(root == NULL) return NULL;
        if(root->val < val) return searchBST(root->right, val);
        if(root->val == val) return root;
        return searchBST(root->left, val);
    }

    // 98 验证二叉搜索树
    bool isValidBST_Traversal(TreeNode* root ,long lowerBound, long upperBound){
        if(root == NULL) return true;
        if(root->val <= lowerBound || root->val >= upperBound) return false;
        return (isValidBST_Traversal(root->left, lowerBound, root->val) && isValidBST_Traversal(root->right, root->val, upperBound));
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST_Traversal(root, LONG_MIN, LONG_MAX);
    }

    // 530 二叉搜索树的最小绝对差
    // 迭代
    int getMinimumDifference(TreeNode* root) {
        TreeNode* pre = new TreeNode(-100001);
        TreeNode* cur = root;
        int minGap = INT_MAX;
        stack<TreeNode*> st;
        while(!st.empty() or cur != NULL){
            if(cur == NULL){
                cur = st.top();st.pop();
                minGap = min(minGap, cur->val - pre->val);
                pre = cur;
                cur = cur->right;
            }
            else{
                st.push(cur);
                cur = cur->left;
            }
        }
        return minGap;
    }


    // 236. 二叉树的最近公共祖先
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        string pPath = findPath(root, p->val, "1");
        string qPath = findPath(root, q->val, "1");
        int index = 1;
        TreeNode* node = root;
        while(1){
            if(pPath[index] == qPath[index]){
                if(pPath[index] == '1'){
                    node = node->left;
                }
                else{
                    node = node->right;
                }
                index++;
            }
            else break;
        }
        return node;
    }

    string findPath(TreeNode *root,  int target, string path){
        if(root == NULL) return "false";
        if(root->val == target) return path;
        string leftPath  = findPath(root->left,  target, path+"1");
        string rightPath = findPath(root->right, target, path+"0");
        if(leftPath != "false") return leftPath;
        if(rightPath != "false") return rightPath;
        return "false";
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        TreeNode* cur = root;
        while(cur != nullptr){
            bool pInLeft = traversal_exist(root->left, p->val);
            bool qInLeft = traversal_exist(root->left, q->val);
            if(pInLeft && qInLeft) cur = cur->left;
            else if(!pInLeft && !qInLeft) cur = cur->right;
            else return cur;
        }
    }

    bool traversal_exist(TreeNode* root, int val){
        if(root == NULL) return false;
        if(root->val == val) return true;
        return traversal_exist(root->left, val) or traversal_exist(root->right, val);
    }

    // 答案递归
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode *q){
        if(root == q || root == p || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor3(root->left, p, q);
        TreeNode* right = lowestCommonAncestor3(root->right, p, q);
        if(left != NULL && right != nullptr) return root;
        if(left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else return nullptr;
    }

    // 235. 二叉搜索树的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

    TreeNode* lowestCommonAncestor_it_235(TreeNode* root, TreeNode* p, TreeNode* q){
        while(root != nullptr){
            if(root->val > p->val && root->val >q->val){
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else break;
        }
        return root;
    }

    //  701 二叉树的插入操作
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* res = root;
        if(root == NULL) return new TreeNode(val);
        TreeNode* pre = NULL;
        int tag;
        while(root != NULL){
            pre = root;
            if(root->val < val){
                root = root->right;
                tag = 1;
            }
            else{
                root = root->left;
                tag = 0;
            }
        }
        if(tag == 1) pre->right = new TreeNode(val);
        else pre->left = new TreeNode(val);
        return res;
    }

    // 450 删除二叉搜索树中的节点
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                TreeNode* res = root->right;
                delete root;
                return res;
            }
            else if(root->right == NULL){
                TreeNode* res = root->left;
                delete root;
                return res;
            }
            else{
                TreeNode* cur = root->right;
                while(cur->left != NULL) cur =cur->left;
                cur->left = root->left;
                TreeNode*tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
    }

    // 669修剪二叉搜索树
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return root;
        if(root->val >= low && root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        else if(root->val > high){
            return trimBST(root->left, low, high);
        }
        else{
            return trimBST(root->right, low, high);
        }
    }

    TreeNode* trimBST_it(TreeNode* root, int low, int high){
        if(root == NULL) return NULL;
        // 先找到在val在范围内的root
        while(root != NULL){
            if(root->val < low) {
                root = root->right;
            }
            else if(root->val > high){
                root = root->left;
            }
            else break;
        }
        TreeNode* cur = root;
        while(cur && cur->left){
            if(cur->left->val < low){
                cur->left = cur->left->right;
            }
            else cur = cur->left;
        }

        cur = root;
        while(cur && cur->right){
            if(cur->right->val > high){
                cur->right = cur->right->left;
            }
            else cur = cur->right;
        }
        return root;
    }

    // 108. 将有序数组转换为二叉搜索树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_Traversal(nums, 0, nums.size());
    }

    TreeNode* sortedArrayToBST_Traversal(vector<int>& nums, int begin, int end){
        if(begin == end) return NULL;
        int mid =(end + begin - 1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST_Traversal(nums, begin, mid);
        root->right = sortedArrayToBST_Traversal(nums, mid+1, end);
        return root;
    }

    TreeNode* sortedArrayToBST_it(vector<int>& nums){
        if (nums.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> nodeQue;
        queue<int> leftQue, rightQue;
        nodeQue.push(root); 
        leftQue.push(0);                    // 0为左区间下标初始位置
        rightQue.push(nums.size() - 1);
        while(!nodeQue.empty()){
            TreeNode* curNode = nodeQue.front(); nodeQue.pop();
            int left = leftQue.front();leftQue.pop();
            int right = rightQue.front();rightQue.pop();
            int mid = (left+right)/2;
            curNode->val = nums[mid];
            if(left <= mid -1){
                curNode->left = new TreeNode(0);
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid-1);
            }
            if(right >= mid+1){
                curNode->right = new TreeNode(0);
                nodeQue.push(curNode->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            }
        }
        return root;
    }

    // 538. 把二叉搜索树转换为累加树
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        stack<TreeNode*> st;
        int acc = 0;
        TreeNode* cur = root;
        while(!st.empty() || cur!=NULL){
            if(cur == NULL){
                cur = st.top();st.pop();
                acc += cur->val;
                cur->val = acc;
                cur = cur->left;
            }
            else{
                st.push(cur);
                cur = cur->right;
            }
        }
        return root;
    }

};

class Solution_findMode{
public:
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



int main(){
    Solution s;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node1->right = node2;
    TreeNode* ress =  s.trimBST_it(node1, 2,4);
    cout<<ress->val;
}
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include <stack>
#include <intrin.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:


    // 438 找到字符串中所有字母异位词
    /* 容器可以直接比较，不用自己写函数比较了！！！！！ */
    vector<int> findAnagrams(string s, string p) {
        vector<int> countp(26);
        for(char ch: p){
            countp[ch-'a']++;
        }
        vector<int> count(26);
        vector<int> res;
        for(int left = 0, right = 0; right < s.size(); right++){
            count[s[right] - 'a']++;
            if(count == countp){
                res.push_back(left);
            }
            if(right - left + 1 == p.size()){
                count[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }

    // 560. 和为 K 的子数组
    // 参考答案，使用前缀和加哈希表优化
    /* 
        map<int, int> mp; // 前缀和 -> 该前缀和出现的次数
    */
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            if(mp.find(pre-k) != mp.end()) count += mp[pre-k];
            mp[pre]++;
        }
        return count;
    }

    // 189. 轮转数组
    // 这种方法不是原地操作！
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tmp(nums.end()-k, nums.end());
        for(vector<int>::iterator it = nums.begin(); it != nums.end()-k; it++){
            tmp.push_back(*it);
        }
        nums = tmp;
    }

    void rotate_Ref(vector<int>& nums, int k){
        k = k % nums.size();
        int count = gcd(k, nums.size());
        for(int start = 0; start < count; start++){
            int current = start;
            int prev = nums[start];
            do{
                int next = (current + k) % nums.size();
                swap(nums[next], prev);
                current = next;
            }while(start != current);
        }
    }

    // 238. 除自身以外数组的乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int multiAcc = 1;
        for(int i = 1; i < nums.size(); i++){
            res[i] = res[i-1]*nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; i--){
            multiAcc = multiAcc * nums[i+1];
            res[i] = res[i] * multiAcc;
        }
        return res;
    }

    // 41. 缺失的第一个正数
    int firstMissingPositive_Ref(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i + 1){
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size()+1;
    }

    // 73. 矩阵置零
    void setZeroes(vector<vector<int>>& matrix) {
        // 用于判断第一列是否存在0
        int colTag = 1;
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0) colTag = 0;
        }
        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0) matrix[0][0] = 0;
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < matrix.size(); i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i = 1; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if(colTag == 0){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }

    void setZeroesRef(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int colTag = 1;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) colTag = 0;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(colTag == 0) matrix[i][0] = 0;
        }
    }

    // 54. 螺旋矩阵
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0, up = 0;
        int right = matrix[0].size()-1, down = matrix.size()-1;
        int tag = 0;
        while(left <= right && up <= down){
            tag = tag % 4;
            if(tag == 0){
                for(int i = left; i <= right; i++){
                    res.push_back(matrix[up][i]);
                }
                up++;
            }
            else if(tag == 1){
                for(int i = up; i <= down; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(tag == 2){
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            else{
                for(int i = down; i >= up; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            tag++;
        }
        return res;
    }


    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int iBegin = 0, jBegin = 0;
        int len = m;
        while(len > 0){
            int x = iBegin, y = jBegin;
            for(int i = 0; i < len - 1; i++){
                int prev = matrix[m-1-y][x+i];
                int tmpy;
                for(int j = 0; j < 4; j++){
                    swap(prev, matrix[x+i][y]);
                    tmpy = m - 1 - (x + i);
                    x = y - i;
                    y = tmpy;
                }
            }
            iBegin++; jBegin++; len -= 2;
        }
    }


    // 240. 搜索二维矩阵 II
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int colLeft = 0, colRight = n - 1;
        int rowLeft = 0, rowRight = m - 1;
        while(colLeft <= colRight){
            int mid = (colRight + colLeft) / 2;
            if(matrix[mid][n-1] == target) return true;
            else if(matrix[mid][n-1] < target) colLeft = mid + 1;
            else colRight = mid - 1;
        }
        while(rowLeft <= rowRight){
            int mid = (rowLeft + rowRight)/2;
            if(matrix[m-1][mid] == target) return true;
            else if(matrix[m-1][mid] > target) rowRight = mid - 1;
            else rowLeft = mid + 1;
        }
        for(int i = colRight + 1; i < m; i++){
            for(int j = rowRight + 1; j < n; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }

    bool searchMatrix1(vector<vector<int>>& matrix, int target){
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target) y--;
            else x++;
        }
        return false;
    }

    // 160. 相交链表
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return NULL;
        int lenA = 0, lenB = 0;
        ListNode* curA = headA, *curB = headB;
        while(curA != NULL){
            lenA++;
            curA = curA->next;
        }
        while(curB != NULL){
            lenB++;
            curB = curB->next;
        }
        curA = headA; curB = headB;
        if(lenA < lenB){
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int i = 0;
        while(i < lenA - lenB){
            curA = curA->next;
            i++;
        }
        while(curA != NULL && curB != NULL){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }

    // 234. 回文链表
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        int length = 1;
        ListNode* tail = head, *cur = head;
        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }
        for(int i = 0; i < length/2; i++) cur = cur->next;
        ListNode* pre = cur;
        cur = cur->next;
        pre->next = NULL;
        while(cur != NULL){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        cur = head;
        while(tail != NULL){
            if(cur->val != tail->val) return false;
            cur = cur->next; tail = tail->next;
        }
        return true;
    }

    // 141. 环形链表
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *low = head, *fast = head;
        while(fast->next != NULL && fast->next->next !=NULL){
            low = low->next;
            fast = fast->next->next;
            if(low == fast) return true;
        }
        return false;
    }

    // 21. 合并两个有序链表
    ListNode* mergeTwoLists_it(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1, list2);
        ListNode* cur1 = list1->next, *pre = list1;
        ListNode* cur2 = list2;
        while(cur1 != NULL && cur2 != NULL){
            if(cur2->val >= pre->val && cur2->val <= cur1->val){
                ListNode* tmp = cur2->next;
                pre->next = cur2;
                cur2->next = cur1;
                pre = cur2;
                cur2 = tmp;
            }
            else{
                pre = pre->next;
                cur1 = cur1->next;
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        else if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }

    // 25. K 个一组翻转链表
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* beginPtr = head, *endPtr = head;
        for(int i = 0; i < k - 1; i++){
            if(endPtr == NULL) return head;
            endPtr = endPtr->next; 
        }
        ListNode* res = endPtr;
        while(endPtr){
            ListNode *pre = beginPtr, *cur = beginPtr->next, *tmp;
            for(int i = 0; i < k - 1; i++){
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            ListNode* preTail = beginPtr;
            if(cur == NULL) return res;
            endPtr = beginPtr = cur;
            for(int i = 0; i < k-1; i++){
                endPtr = endPtr->next;
                if(endPtr == NULL){
                    preTail->next = beginPtr;
                    return res;
                }
            }
            preTail->next = endPtr;
        }
        return res;
    }

    // 138. 随机链表的复制
    Node* copyRandomList(Node* head) {
        if(head == NULL) return nullptr;
        unordered_map<Node*, Node*> unmap;
        Node* cur = head;
        while(cur != NULL){
            unordered_map<Node*, Node*>:: iterator it = unmap.find(cur);
            Node* node = nullptr;
            if(it != unmap.end()){
                node = it->second;
            }
            else{
                node = new Node(cur->val);
                unmap.insert(pair<Node*, Node*>(cur, node));
            }

            if(cur->random != NULL){
                Node* randomNode = nullptr;
                it = unmap.find(cur->random);
                if(it != unmap.end()){
                    randomNode = it->second;
                }
                else{
                    randomNode = new Node(cur->random->val);
                    unmap.insert(pair<Node*, Node*>(cur->random, randomNode));
                }
                node->random = randomNode;
            }

            if(cur->next != NULL){
                it = unmap.find(cur->next);
                if(it != unmap.end()){
                    node->next =it->second;
                }
                else{
                    node->next = new Node(cur->next->val);
                    unmap.insert(pair<Node*, Node*>(cur->next, node->next));
                }
            }
            cur = cur->next;
        }
        return unmap.find(head)->second;
    }


    // 148. 排序链表
    ListNode* sortList(ListNode* head){
        int length = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            length++;
        }
        return sortList_Traversal(head, length);
    }
    ListNode* sortList_Traversal(ListNode* head, int k){
        if(k == 2){
            if(head->val > head->next->val){
                // cout << head->val << head->next->val;
                int tmp = head->val;
                head->val = head->next->val;
                head->next->val = tmp;
            }
            return head;
        }
        else if(k >= 3){
            int mid = k / 2;
            ListNode* rightHead = head, *pre = nullptr;
            for(int i = 0; i < mid; i++){
                pre = rightHead;
                rightHead = rightHead->next;
            }
            pre->next = NULL;
            head = sortList_Traversal(head, mid);
            rightHead = sortList_Traversal(rightHead, k - mid);
            ListNode* res  = mergeTwoLists(head, rightHead);
            return res;
        }
        return head;
    }


    // 23. 合并 K 个升序链表
    // 最笨的办法，一个一个合并
    ListNode* mergeKLists_1(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        for(ListNode* head : lists){
            res = mergeTwoLists(res, head);
        }
        return res;
    }

    // 两两合并
    ListNode* mergeKLists_2(vector<ListNode*>& lists){
        return mergeKL(lists, 0, lists.size()-1);
    }

    ListNode* mergeKL(vector<ListNode*>& lists, int listBegin, int listEnd){
        if(listBegin == listEnd) return lists[listBegin];
        else if(listBegin > listEnd) return NULL;
        else{
            int mid = (listBegin + listEnd) / 2;
            return mergeTwoLists(mergeKL(lists, listBegin, mid), mergeKL(lists, mid+1, listEnd));
        }
    }

    // 优先级队列
    class cmp{
    public:
        bool operator()(ListNode*& a, ListNode*& b){
            return (a->val > b->val);
        }
    };



    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<ListNode*, vector<ListNode*>, cmp> prique;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL) prique.push(lists[i]);
        }
        return mergeKLists_pri(prique);
    }

    ListNode* mergeKLists_pri(priority_queue<ListNode*, vector<ListNode*>, cmp>& prique){
        if(prique.empty()) return NULL;
        ListNode* node = prique.top(); prique.pop();
        if(node->next) prique.push(node->next);
        node->next = mergeKLists_pri(prique);
        return node;
    }

    // 543. 二叉树的直径
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameterOfBinaryTreeRecursion(root, res);
        return res;
    }

    int diameterOfBinaryTreeRecursion(TreeNode* root, int& res){
        if(root == nullptr) return 0;
        int leftDepth = diameterOfBinaryTreeRecursion(root->left, res) + 1;
        int rightDepth = diameterOfBinaryTreeRecursion(root->right, res) + 1;
        if(leftDepth + rightDepth - 2 > res) res = leftDepth + rightDepth - 2;
        return max(leftDepth, rightDepth);
    }

    // 230. 二叉搜索树中第K小的元素
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur != NULL){
            if(cur == NULL){
                cur = st.top(); st.pop();
                count++;
                if(count == k) return cur->val;
                cur = cur->right;
            }
            else{
                st.push(cur);
                cur = cur->left;
            }
        }
        return 0;
    }

    // 114. 二叉树展开为链表
    // 前序遍历，但是空间复杂度不是o(1)
    void flatten_it_preorder(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev = NULL;
        while(!st.empty()){
            TreeNode* node = st.top();st.pop();
            if(prev){
                prev->right = node;
                prev->left = NULL;
            }
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            prev = node; 
        }
    }

    // 递归
    // 空间复杂度也不是o(1)
    void flatten_recursion(TreeNode* root){
        if(root == NULL) return;
        flatten_recursion(root->right);
        flatten_recursion(root->left);
        root->left = NULL;
        root->right = preNode114;
        preNode114 = root;
    }

    // 空间复杂度o(1)的方法：将右子树挪到左子树的最右节点。
    void flatten(TreeNode* root){
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                auto next = curr->left;
                auto predecessor = next;
                while(predecessor->right != NULL){
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }

    // 437. 路径总和 III
    // 递归回溯！！！！背吧！
    int dfs(TreeNode *root, long long curr, int targetSum){
        if(root == NULL) return 0;
        int ret = 0;
        // 到当前节点的前缀和
        curr += root->val;
        if(prefix437.count(curr - targetSum)){
            ret = prefix437[curr - targetSum];
        }
        prefix437[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix437[curr]--;
        return ret;
    }
        int pathSum(TreeNode* root, int targetSum) {
        prefix437[0] = 1;
        return dfs(root, 0, targetSum);
    }

    // 124. 二叉树中的最大路径和
    int maxPathSum_1(TreeNode* root) {
        if(root == NULL) return 0;
        unordered_map<TreeNode*, vector<int>> dp;
        dp.insert({NULL, {INT16_MIN, INT16_MIN, INT16_MIN, INT16_MIN}});
        int res = INT_MIN;
        maxPathSum_Recursion(root, dp, res);
        return res;
    }

    void maxPathSum_Recursion(TreeNode* root, unordered_map<TreeNode*, vector<int>>& dp, int& res){
        if(root == NULL) return;
        maxPathSum_Recursion(root->left, dp, res);
        maxPathSum_Recursion(root->right, dp, res);
        vector<int> cur(4, 0);
        vector<int> left = dp[root->left];
        vector<int> right = dp[root->right];
        cur[1] = root->val + max(max(left[1], left[2]), left[3]);
        cur[2] = root->val + max(max(right[1], right[2]), right[3]);
        cur[0] = max(cur[1], cur[2]) - root->val;
        cur[3] = root->val;
        dp.insert({root, cur});
        res = max(res, findMax(cur));

    }

    int findMax(vector<int> nums){
        int res = INT_MIN;
        for(int num: nums){
            if(num > res) res = num;
        }
        return max(res, nums[1] + nums[2] - nums[3]);
    }

    // 参考答案
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int res = INT_MIN;
        maxGain(root, res);
        return res;
    }

    int maxGain(TreeNode* node, int& res){
        if(node == NULL) return 0;

        int leftGain = max(maxGain(node->left, res), 0);
        int rightGain = max(maxGain(node->right, res), 0);

        int curPath = node->val + leftGain + rightGain;
        res = max(res, curPath);
        return node->val + max(leftGain, rightGain);
    }

    

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    TreeNode* preNode114;
    unordered_map<long long, int> prefix437;
};

// 146. LRU 缓存
struct DLinkedNode{
    int key, value;
    DLinkedNode* prev, *next;
    DLinkedNode():key(0), value(0), prev(NULL), next(NULL){}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(NULL), next(NULL) {}
};

class LRUCache{
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head, *tail;
    int size, capacity;
public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(cache.find(key) == cache.end()) return -1;
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value){
        if(cache.find(key) != cache.end()){
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else{
            DLinkedNode* node = new DLinkedNode(key, value);
            // 放入到cache中
            cache[key] = node;
            // 放到表头
            addToHead(node);
            size++;
            // 处理超出cache容量的情况
            if(size > capacity){
                size--;
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
            }
        }
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode* node){
        // 注意此时这个节点还在cache中
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

};

class Solution_994{
private:
    int cnt;
    // dis用来记时间
    int dis[10][10];
    int dir_x[4]={0, 1, 0, -1};
    int dir_y[4]={1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int>>& grid){
        queue<pair<int, int>> Q;
        // 所有位置设为-1
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int m = grid[0].size(), n = grid.size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    Q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
                else if(grid[i][j] == 1) cnt += 1;
            }
        }

        while(!Q.empty()){
            pair<int, int> x = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++){
                int tx = x.first + dir_x[i];
                int ty = x.second + dir_y[i];
                // 判断是否出界, 或者已经被传播为坏橘子（dis[tx][ty] != -1）， 或者为空地
                if(tx < 0 || tx >= n || ty < 0 || ty >= m || dis[tx][ty] != -1 || grid[tx][ty] == 0) continue;
                // 新腐化的坏橘子
                dis[tx][ty] = dis[x.first][x.second] + 1;
                Q.push(make_pair(tx, ty));
                cnt -= 1;
                ans = dis[tx][ty];
                if (!cnt) break;
            }
        }
        return cnt ? -1:ans;
    }
};

class Solution207_dfs {
private:
    vector<vector<int>> edges;
    vector<int> visited;
public:
    bool dfs(int u){
        visited[u] = 1;
        for(int v: edges[u]){
            if(visited[v] == 0){
                if(dfs(v) == false) return false;
            }
            else if (visited[v] == 1){
                return false;
            }
        }
        visited[u] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        // edges[i]代表目的节点为i的所有源节点的集合
        for (const auto& info: prerequisites){
            // 这里两个变量交换位置也可以，意思变为：源节点为i的所有目的节点的集合。
            // 但是不换比较好，具有实际意义：学某门课的前提课程
            edges[info[1]].push_back(info[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
};

class Solution207_bfs{
    vector<vector<int>> edges;
    vector<int> indeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(const vector<int>& info: prerequisites){
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int visited = 0;
        while(!q.empty()){
            visited++;
            int u = q.front();q.pop();
            // 前导为u的课程。
            for(int v: edges[u]){
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }

        return visited == numCourses;
    }
};

// 210. 课程表 II
class Solution210 {
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites){
            // 先修课程为i的课程集合
            edges[info[1]].push_back(info[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                dfs(i, numCourses);
            }
        }
        reverse(res.begin(), res.end());
        if(res.size() == numCourses) return res;
        return {};
    }

    bool dfs(int n, int& numCourses){
        visited[n] = 1;
        for(int node: edges[n]){
            if(visited[node] == 0){
                if(dfs(node, numCourses) == false) return false;
            }
            else if(visited[node] == 1){
                return false;
            }
        }
        visited[n] = 2;
        res.push_back(n);
        return true;
    }
};

class Solution210_bfs{
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> res;
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(vector<int> info : prerequisites){
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int visit = numCourses;
        while(!q.empty()){
            int course = q.front();q.pop();
            visit--;
            res.push_back(course);
            for(int num : edges[course]){
                indeg[num]--;
                if(indeg[num] == 0) q.push(num);
            }
        }
        if(visit) return {};
        return res;
    }
};


int main(){
    // Solution s;
    // ListNode* head = new ListNode(0);
    // ListNode* node1 = new ListNode(5);
    // ListNode* node2 = new ListNode(3);
    // ListNode* node3 = new ListNode(1);
    // ListNode* node4 = new ListNode(4);
    // head->next = node1;
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // ListNode* node = s.sortList(head);
    // while(node){
    //     cout << node->val;
    //     node = node->next;
    // }
    // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> prque;
    // prque.push(pair<int, int>(1, 2));
    // prque.push(pair<int, int>(2, 3));
    // cout << prque.top().second;
    Solution210 s;
    vector<vector<int>> prerequisites{{0,1}, {1, 2}, {2, 3}, {3, 4}};
    vector<int> res = s.findOrder(5, prerequisites);
    for(int num: res){
        cout << num << endl;
    }
}


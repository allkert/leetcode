#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>

using namespace std;

    // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
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






private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
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
}


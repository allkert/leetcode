#include<iostream>
#include<vector>
#include<string>
#include <stack>
#include <queue>

using namespace std;

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix){
        Trie* node = this;
        for(char ch: prefix){
            ch -= 'a';
            if(node->children[ch] == NULL) return NULL;
            node = node->children[ch];
        }
        return node;
    }
public:
    Trie() : children(26), isEnd(false){}
    
    void insert(string word) {
        Trie* node = this;
        for(char ch : word){
            ch -= 'a';
            if(node->children[ch] == NULL){
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }

};

class Solution22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking("", res, n, n);
        return res;
    }

    void backtracking(string path, vector<string>& res, int leftNum, int rightNum){
        if(leftNum == 0 && rightNum == 0) res.push_back(path);
        else if(leftNum == rightNum){
            backtracking(path+'(', res, leftNum - 1, rightNum);
        }
        else{
            if(leftNum != 0) backtracking(path+'(', res, leftNum-1, rightNum);
            backtracking(path+')', res, leftNum, rightNum-1);
        }
    }
};

// 记得滚去看答案
class Solution79 {
private:
    vector<int> tx{1, -1, 0, 0};
    vector<int> ty{0, 0, 1, -1};

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> used(board.size(), vector<int>(board[0].size()));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtracking(board, used, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, vector<vector<int>>& used, string word, int begin, int x, int y){
        if(begin == word.size()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || used[x][y] || word[begin] != board[x][y]) return false;
        used[x][y] = 1;
        bool tag = false;
        for(int i = 0; i < 4; i++){
            tag = tag || backtracking(board, used, word, begin+1, x + tx[i], y + ty[i]);
        }
        used[x][y] = 0;
        return tag;
    }
};

class Solution_74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while(row < matrix.size() && col >= 0){
            if(matrix[row][col] > target) col--;
            else if(matrix[row][col] < target) row++;
            else return true;
        }
        return false;
    }
};

class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            // 如果左边有序
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] > target){
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            // 右边有序
            else{
                if(nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }

};

class Solution153 {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
    }
    int binarySearch(vector<int>& nums, int begin, int end){
        if(begin > end) return INT_MAX;
        if(nums[begin] <= nums[end]) return nums[begin];
        int mid = (begin + end) / 2;
        if(nums[mid] >= nums[begin]){
            return min(nums[begin], binarySearch(nums, mid+1, end));
        }
        else{
            return min(nums[mid], binarySearch(nums, begin, mid - 1));
        }
    }
};

// 155. 最小栈
class MinStack {
    stack<int> minStack;
    stack<int> supStack;
public:
    MinStack() {
        supStack.push(INT_MAX);
    }
    
    void push(int val) {
        minStack.push(val);
        supStack.push(min(supStack.top(), val));
    }
    
    void pop() {
        minStack.pop();
        supStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return supStack.top();
    }
};


class Solution394 {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch != ']') st.push(ch);
            // 遇到反中括号
            else{
                string temp = "";
                while(!st.empty()){
                    char t = st.top(); st.pop();
                    if(t == '[') break;
                    else temp = t + temp;
                }
                string strCount = "";
                while(!st.empty()){
                    char t = st.top(); 
                    if(t >= '0' && t <= '9'){
                        strCount = t + strCount;
                        st.pop();
                    }
                    else break;
                }
                int count = stoi(strCount);
                while(count){
                    for(char c : temp){
                        st.push(c);
                    }
                    count--;
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        cout << res;
        return res;
    }
};

class Solution394_recursion{
string src;
size_t ptr;
public:
    // 获取数字部分
    int getDigits(){
        int ret = 0;
        while(ptr < src.size() && isdigit(src[ptr])){
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString(){
        // 终止条件
        if(ptr == src.size() || src[ptr] == ']') return "";
        char cur = src[ptr]; int repTime = 1;
        string ret;
        // 如果当前字符是数字
        if(isdigit(cur)){
            repTime = getDigits();
            // 数字结束后一定是左括号，过滤左括号
            ptr++;
            // 得到字符串，重复很多次
            string str = getString();
            ptr++;
            while(repTime--) ret += str;
        }
        // 如果是字母
        else if(isalpha(cur)){
            ret = string(1, src[ptr++]);
        }

        return ret + getString();

    }
    string decodeString(string s){
        src = s;
        ptr = 0;
        return getString();
    }
};

class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

// 记得看答案！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
class Solution215 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> prique;
        for(int num : nums){
            prique.push(num);
            if(prique.size() > k) prique.pop();
        }
        return prique.top();
    }
};

class Solution215_Ref1{
    // 基于快排的选择方法
    // 明白快排的原理，降序快排，只要一轮排序中provit出现在下标为k的地方，则为第k大的元素
    int findKthLargest_quickSort(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);    
    }
    int quickSelect(vector<int> &nums, int left, int right, int k){
        if(left == right) return nums[k-1];
        int provit = nums[left], l = left - 1, r = right + 1;
        while(l < r){
            do ++l; while(nums[l] > provit);
            do --r; while(nums[r] < provit);
            if (l < r) swap(nums[l], nums[r]);
        }
        if(r + 1 >= k) return quickSelect(nums, left, r, k);
        else return quickSelect(nums, r + 1, right, k);
    }

    // 基于堆排序,但是你要自己实现,不然回去等通知
    // 官方使用大根堆
    // 首先自己实现一个大根堆
    void maxHeapify(vector<int>& arr, int curIndex, int heapSize){
        // 左孩子和右孩子
        int left = 2 * curIndex + 1, right = 2 * curIndex + 2, largest = curIndex;
        // 左孩子的值是否大于当前节点的值
        if(left < heapSize && arr[left] > arr[largest]) largest = left;
        if(right < heapSize && arr[right] > arr[largest]) largest = right;
        if(curIndex != largest){
            // 此时交换了节点值,可能破坏了被交换的那个子节点对应的子树的堆排序
            swap(arr[curIndex], arr[largest]);
            maxHeapify(arr, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int> &arr, int heapSize){
        for(int i = heapSize / 2; i >=0; i--){
            maxHeapify(arr, i, heapSize);
        }
    }

    int findKthLargest_MaxHeap(vector<int>& nums, int k){
        // 建立大根堆
        buildMaxHeap(nums, nums.size());
        // for(int i = 0; i < nums.size(); i++){
        //     cout << nums[i];
        // }
        // 进行k-1次最大值的剔除
        for(int i = 1; i < k; i++){
            swap(nums[0], nums[nums.size()-i]);
            maxHeapify(nums, 0, nums.size() - i);
        }
        return nums[0];
    }

};



class Solution118 {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1,1}};
        vector<int>dp{1,1};
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1, 1});
        for(int i = 2; i < numRows; i++){
            vector<int> nextdp(i+1);
            nextdp[0] = dp[0];
            nextdp[i] = dp[i-1];
            for(int j = 1; j < i; j++){
                nextdp[j] = dp[j-1] + dp[j];
            }
            dp = nextdp;
            res.push_back(dp);
        }
        return res;
    }
};

// 42. 接雨水
class Solution_42{
public:
    int trap(vector<int>& height){
        // 单调递减栈
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int mid = st.top(); st.pop();
                if(!st.empty()){
                    ans += (min(height[i], height[st.top()]) - height[mid]) * (i - st.top() - 1); 
                }
            }
            st.push(i);
        }
        return ans;
    }
};

// 84 柱状图中的最大矩形
class Solution_84 {
public:


    int largestRectangleArea(vector<int>& heights){
        // 从栈底到栈顶是单调增的, 存高度对应的下标。
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int max_ = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int mid = st.top(); st.pop();
                // 从 st.top() 到 i 这个区间里面全部是高度同样可以视为heights[mid]的柱子。
                max_ = max(max_, (i - st.top() - 1) * heights[mid]);
            }
            st.push(i);
        }
        return max_;
    }
};

// 小根堆的底层实现
class MinHeap{
private:
    vector<int> data;
    // siftUp: 从下往上调整, 保证堆的性质
    // 将子节点不停的和父节点比较, 如果子节点小于父节点, 则交换
    // 这个并不会破坏父节点的另外一个子树的堆性质
    void siftUp(int k){
        while(k > 0 && data[(k-1)/2] > data[k]){
            // (k-1)/2 是父节点的下标, 注意从0开始
            swap(data[(k-1)/2], data[k]);
            k = (k-1)/2;
        }
    }

    // siftDown: 从上往下调整, 保证堆的性质
    void siftDown(int k){
        // 判断条件确保有孩子节点存在
        while(2 * k + 1 < data.size()){
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            // 找到当前节点和左右孩子节点中最小的那个
            int smallest = k;
            if(data[left] < data[smallest]) smallest = left;
            if(right < data.size() && data[right] < data[smallest]) smallest = right;
            // 最小的是当前节点, 说明已经满足堆性质
            if(smallest == k) break;
            swap(data[k], data[smallest]);
            // 被交换的子节点的堆性质可能被破坏，因此需要继续向下检查
            k = smallest;
        }
    }
public:
    // 作为数据结构应该提供的操作接口
    void push(int val){
        data.push_back(val);
        // 向上调整
        siftUp(data.size() - 1);
    }
    void pop(){
        // 把第一个元素放到最后去
        swap(data[0], data[data.size()-1]);
        // 向下调整第一个元素
        data.pop_back();
        siftDown(0);
    }
    int top(){
        return data[0];
    }
    bool empty(){
        return data.empty();
    }
    int size(){
        return data.size();
    }
};



int main(){
    MinHeap minHeap;
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(1);
    minHeap.push(15);
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;
}
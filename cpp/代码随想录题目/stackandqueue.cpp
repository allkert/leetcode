# include<iostream>
# include<string>
# include<algorithm>
# include<vector>
# include<queue>
# include<stack>
# include<sstream>
# include<deque>
# include<map>
#include <unordered_map>


using namespace std;

// 232 用栈实现队列
/* 思路是用其中一个栈当作队列，另外一个栈用于临时存放，这样比较麻烦 */
class MyQueue {
public:
    MyQueue() {
        _size = 0;
    }
    
    void push(int x) {
        if(stack2.empty()){
            stack1.push(x);
        }
        else{
            stack2.push(x);
        }
        _size++;
    }
    
    int pop() {
        int tmp;
        while(!stack1.empty()){
            tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int res = stack2.top();
        stack2.pop();
        _size--;
        while(!stack2.empty()){
            tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }
        return res;
    }
    
    int peek() {
        int tmp;
        while(!stack1.empty()){
            tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int res = stack2.top();
        while(!stack2.empty()){
            tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }
        return res;
    }
    
    bool empty() {
        return _size == 0? true:false;
    }
private:
    int _size;
    // stack1
    stack<int> stack1;
    // queue2
    stack<int> stack2;
};

class MyQueue_Ref{
public:     
    MyQueue_Ref() {
        _size =0;
    }

    void push(int x){
        stIn.push(x);
        _size++;
    }

    int pop(){
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        _size--;
        return res;
    }

    int peek(){
        int res = this->pop();
        stOut.push(res);
        _size++;
        return res;
    }

    bool empty(){
        return _size == 0? true:false;
    }
private:
    stack<int> stIn;
    stack<int> stOut;
    int _size;
};

// 225用队列实现栈
class MyStack {
public:
    MyStack() {
        _size = 0;
    }
    
    void push(int x) {
        q1.push(x);
        _size++;
    }
    
    int pop() {
        int res;
        for(int i = 0; i < _size - 1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        res = q1.front();
        q1.pop();
        swap(q1, q2);
        _size--;
        return res;
    }
    
    int top() {
        int res = this->pop();
        this->push(res);
        return res;
    }
    
    bool empty() {
        return _size == 0? true:false;
    }
private:
    int _size;
    queue<int> q1;
    queue<int> q2;
};


class Solution {
public:
    // 20. 有效的括号
    bool isValid(string s) {
        stack<char> cstack;
        for(char ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                cstack.push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}'){
                if(cstack.empty()) return false;
                switch(cstack.top()){
                    case '(':
                        if(ch != ')') return false;
                        break;
                    case '[':
                        if(ch != ']') return false;
                        break;
                    case '{':
                        if(ch != '}') return false;
                        break;
                }
                cstack.pop();
            }
        }

        return cstack.empty()? true:false;
    }

    // 1047. 删除字符串中的所有相邻重复项
    string removeDuplicates(string s) {
        stack<char> st;
        for(char ch: s){
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string res;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }

    // 150. 逆波兰表达式求值
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string str:tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(str == "+") st.push(num1+num2);
                else if(str == "-") st.push(num2-num1);
                else if(str == "*") st.push(num1*num2);
                else if(str == "/") st.push(num2/num1);
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }

    // 239.滑动窗口的最大值
    // 我的解法，在最差的情况下，时间复杂度为o(nk)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int index = 0;
        int max_ = findMax(nums, 0, k - 1, &index);
        vector<int> res{max_};
        for(int i = 0, j = k; j < nums.size(); i++, j++){
            if(nums[j] >= max_){
                max_ = nums[j];
                index = j;
            }
            else{
                // 最大值不在窗口了
                if(i == index){
                    max_ = findMax(nums, i + 1, j, &index);
                }
            }
            res.push_back(max_);
        }
        return res;
    }
    int findMax(vector<int>& nums, int start, int end, int *index){
        int max_ = nums[start];
        *index = start;
        for(int i = start; i <= end; i++){
            if(nums[i] >= max_){
                max_ = nums[i];
                *index = i;
            }
        }
        return max_;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> res;
        MyOrderedQueue dq;
        for(int i = 0; i < k; i++){
            dq.push(nums[i]);
        }
        res.push_back(dq.front());
        for(int j = k; j < nums.size(); j++){
            dq.push(nums[j]);
            dq.popright(nums[j-k]);
            res.push_back(dq.front());
        }
        return res;
    }

    
    // 347. 前 K 个高频元素
    class mycomparison{
    public:
        bool operator()(const pair<int, int>& l, const pair<int, int>& h){
            return l.second > h.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        // 统计频率
        for(int num: nums){
            count[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for(unordered_map<int, int>::iterator it = count.begin();it != count.end();it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return res;
    }


    class MyOrderedQueue{
    public:
        deque<int> dq;
        void popright(int val){
            if(!dq.empty() && dq.front() == val){
                dq.pop_front();
            }
        }

        void push(int x){
            while(!dq.empty() && x > dq.back()){
                dq.pop_back();
            }
            dq.push_back(x);
        }

        int front(){
            return dq.front();
        }
    };

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
    Solution sol;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k;
    vector<int> res = sol.maxSlidingWindow(nums, 3);
    for(int r: res){
        cout << r <<'\t';
    }
}
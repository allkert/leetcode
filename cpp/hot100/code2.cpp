#include<iostream>
#include<vector>
#include<string>
#include <stack>

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
    int getDigits(){
        int ret = 0;
        while(ptr < src.size() && isdigit(src[ptr])){
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString(){
        if(ptr == src.size() || src[ptr] == ']') return "";
        char cur = src[ptr]; int repTime = 1;
        string ret;
        if(isdigit(cur)){
            repTime = getDigits();
            // 过滤左括号
            ptr++;
            string str = getString();
            ptr++;
            while(repTime--) ret += str;
        }
        else if(isalpha(cur)){
            ret = string(1, src[ptr++]);
        }

    }
    string decodeString(string s){

    }
};

int main(){
    Solution394 s;
    s.decodeString("2[a2[bc]]");
}
# include<iostream>
# include<string>
# include<algorithm>
# include<limits>
# include<queue>
# include<vector>
# include<stack>
# include<list>
# include <map>
#include <unordered_map>

using namespace std;

class Solution_77{
public:
    
    // 77 组合
    void backtracking_combine(vector<vector<int>>& res, int n, int k, int low, vector<int> path){
        int lenPath = path.size();
        if(lenPath == k) {
            res.push_back(path);
            return;
        }
        for(int i = low; i <= n - (k - 1 - lenPath); i++){
            path.push_back(i);
            backtracking_combine(res, n, k, i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        backtracking_combine(res, n, k, 1, vector<int>());
        return res;
    }

};


// 216. 组合总和 III
class Solution_216{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int begin){
        if(k == 0){
            if(n == 0) res.push_back(path);
            return;
        }
        if(n <= 0) return;
        for(int i = begin; i <= 10-k; i++){
            path.push_back(i);
            backtracking(n - i, k - 1, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        backtracking(n, k, 0);
        return res;
    }
};

class Solution{
private:
    map<char, string> digits_17{{'2',"abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
    // 17. 电话号码的字母组合
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        backtracking_17(res, digits, 0, "");
        return res;
    }

    void backtracking_17(vector<string>& res, string digits, int index, string path){
        if(digits.length() == 0) return;
        if(index == digits.length()) res.push_back(path);
        for(char ch: digits_17[digits[index]]){
            backtracking_17(res, digits, index+1, path+ch);
        }
    }

    // 39. 组合总和
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        backtracking_39(res, 0, candidates, target, vector<int>());
        return res;
    }

    void backtracking_39(vector<vector<int>> res, int index, vector<int>& candidates, int target, vector<int> path){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(candidates[index] > target) return;
        for(int i = index; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            backtracking_39(res, i, candidates, target-candidates[i], path);
            path.pop_back();
        }
    }
};


// 40. 组合总和 II
class Solution_40_1 {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    void backtracking(vector<int>& candidates, int index, int target){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size() && candidates[i] <= target; i++){
            if(i!=0 and candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target);
        return res;
    }
};

// 131分割回文串
class Solution_131 {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    bool isPalindrome(string s, int begin, int end){
        while(begin<end){
            if(s[begin++] != s[end++]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
    void backtracking(string s, int start){
        if(start == s.length()) res.push_back(path);
        for(int i = start; i < s.length(); i++){
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(i, start-i+1));
                backtracking(s, i+1);
                path.pop_back();
            }
        }
    }
};

// 93复原IP地址
class Solution_93 {
private:
    vector<string> res;
public:
    void backtracking(string s, int startIndex, int tag, string path){
        if(startIndex >= s.length()){
            if(tag == 0){
                path.resize(path.length()-1);
                res.push_back(path);
            }
            return;
        }
        if(s[startIndex] == '0'){
            backtracking(s, startIndex+1, tag-1, path+'0'+'.');
        }
        else{
            for(int i = 1; i <= 3 && startIndex+i <= s.length(); i++){
                int singleIP = stoi(s.substr(startIndex, i));
                if(singleIP <= 255){
                    backtracking(s, startIndex+i, tag-1, path+s.substr(startIndex, i)+'.');
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 4, "");
        return res;
    }
};

// 参考 想想为什么参考答案的效率这么高
class Solution_39_ref{
private:
    vector<string> res;
    bool isVaild(const string& s, int start, int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
    void backtracking(string& s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isVaild(s, startIndex, s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isVaild(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                backtracking(s, i+2, pointNum+1);
                s.erase(s.begin()+i+1);
            }
            else break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if (s.size() < 4 || s.size() > 12) return res; // 算是剪枝了
        backtracking(s, 0, 0);
        return res;
    }

};


class Solution_78 {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(int startIndex, vector<int>& nums){
        res.push_back(path);
        if(startIndex == nums.size()){
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(i+1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(0, nums);
        return res;
    }
};


// 90 子集Ⅱ
class Solution_90 {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(path);
        if(startIndex >= nums.size()) return;
        for(int i = startIndex; i < nums.size(); i++){
            if(i > startIndex && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
};


// 非递减子序列
class Solution_491 {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() >= 2) res.push_back(path);
        if(startIndex >= nums.size()) return;
        for(int i = startIndex; i < nums.size(); i++){
            if(i > startIndex && find(nums.begin()+startIndex, nums.begin()+i, nums[i]) != nums.begin()+i) 
                continue;
            if(path.empty() || nums[i] >= path[path.size()-1]){
                path.push_back(nums[i]);
                backtracking(nums, i+1);
                path.pop_back();
            }
        }
    }
};

class Solution_46 {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(vector<bool>& used, vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(used, nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(used, nums);
        return res;
    }
};

class Solution_47{
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

};

class Solution_332{
private:
    vector<string> res = {"JFK"};
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);
        quicksort(tickets, 0, tickets.size()-1);
        backtracking(tickets, used, "JFK");
        return res;
    }

    void quicksort(vector<vector<string>>& tickets, int beginIndex, int endIndex){
        int left = beginIndex, right = endIndex;
        if(left >= right) return;
        int midTag = beginIndex;
        while(left < right){
            while(left < right && compare(tickets[midTag], tickets[right])) right--;
            if(left < right){
                swap(tickets[midTag], tickets[right]);
                midTag = right;
            }
            while(left < right && compare(tickets[left], tickets[midTag])) left++;
            if(left < right){
                swap(tickets[left], tickets[midTag]);
                midTag = left;
            }
        }
        quicksort(tickets, beginIndex, midTag-1);
        quicksort(tickets, midTag+1, endIndex);
    }

    bool compare(vector<string> a, vector<string> b){
        for(int i = 0; i < a[1].size(); i++){
            if(a[1].at(i) > b[1].at(i)) return false;
            else if(a[1].at(i) < b[1].at(i)) return true;
        }
        return true;
    }

    bool backtracking(vector<vector<string>>& tickets, vector<bool>& used, string place){
        if(res.size() == tickets.size()+1) return true;
        for(int i = 0; i < tickets.size(); i++){
            if(!used[i] && tickets[i][0] == place){
                used[i] = true;
                res.push_back(tickets[i][1]);
                if(backtracking(tickets, used, tickets[i][1])){
                    return true;
                }
                used[i] = false;
                res.pop_back();
            }
        }
        return false;
    }
};

class Solution_332_ref{
private:
    unordered_map<string, map<string, int>> targets;
    
    bool backtracking(int ticketNum, vector<string>& result){
        if(result.size() == ticketNum + 1){
            return true;
        }
        for(pair<const string ,int>& target: targets[result[result.size() - 1]]){
            if(target.second > 0){
                result.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        targets.clear();
        vector<string> result;
        for(const vector<string>& vec: tickets){
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JKF");
        backtracking(tickets.size(), result);
        return result;
    }
};

// 51 N皇后
class Solution_51 {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    vector<vector<string>> solveNQueens(int n) {
        path = vector<string> (n, string(n,'.'));
        backtracking(0, n);
        return res;
    }
    bool check(int row, int col, int n){
        // check line and rou
        for(int i = 0; i < n; i++){
            if(path[row][i] != '.' || path[i][col] != '.') return false;
        }
        // 对角线
        int diagonalRow = row - min(row, col);
        int diagonalCol = col - min(row, col);
        while(diagonalRow < n && diagonalCol < n){
            if(path[diagonalRow++][diagonalCol++] != '.') return false;
        }
        // 反对角线
        int antiDiagonalRow, antiDiagonalCol;
        if(row + col < n - 1){
            antiDiagonalRow = row + col;
            antiDiagonalCol = 0;
        }
        else{
            antiDiagonalRow = n - 1;
            antiDiagonalCol = col - (n - 1 - row);
        }
        while(antiDiagonalRow >= 0 && antiDiagonalCol < n){
            if(path[antiDiagonalRow--][antiDiagonalCol++] != '.') return false;
        }
        return true;
    }

    void backtracking(int row, int n){
        if(row == n){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(check(row, i, n)){
                path[row][i] = 'Q';
                backtracking(row+1, n);
                path[row][i] = '.';
            }
        }
    }

};

// 37 解数独
class Solution_37 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0, 0);
    }

    bool check(vector<vector<char>>& board, int row, int col, char put){
        // check row and col
        for(int i = 0; i < 9; i++){
            if(board[row][i] == put || board[i][col] == put) return false;
        }
        // check 3x3
        row -= row%3;
        col -= col%3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[row+i][col+j] == put) return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board, int row, int col){
        if(col == 9){
            col = 0;
            row++;
        }
        if(row == 9){
            return true;
        }
        if(board[row][col]!='.'){
            return backtracking(board, row, col+1);
        }
        for(char ch = '1'; ch <= '9'; ch++){
            if(check(board, row, col, ch)){
                board[row][col] = ch;
                if(backtracking(board, row, col+1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
};

int main(){
    char a = '1';
    a++;
    cout<<a;
    Solution_51 s;
}
# include<iostream>
# include<string>
# include<algorithm>
# include<limits>
# include<queue>
# include<vector>
# include<stack>
# include<list>
# include <map>

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

int main(){
    return 0;
}
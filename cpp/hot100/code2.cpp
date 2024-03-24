#include<iostream>
#include<vector>
#include<string>

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


int main(){
    Solution22 s;
    vector<string> res;
    res = s.generateParenthesis(2);
    for(string s : res){
        cout << s << endl;
    }
    return 0;
}
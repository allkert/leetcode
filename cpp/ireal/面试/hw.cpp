#include<iostream>
#include<vector>

using namespace std;

void backtrack(int cur, vector<int> path, int n, int m, vector<vector<int>>& res){
    int curlen = path.size();
    if(curlen == m){
        res.push_back(path);
        return;
    }
    if(cur > n) return;
    for(int i = cur; i <= n; ++i){
        path.push_back(i);
        backtrack(i + 1, path, n, m, res);
        path.pop_back();
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res;
    backtrack(1, {}, n, m, res);
    for(auto r : res){
        for(int i = 0; i < r.size() - 1; ++i){
            cout << r[i] << " ";
        } 
        cout << *r.rbegin() << endl;
    }
}
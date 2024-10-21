#include <iostream>
#include <vector>
using namespace std; 

int calculate(vector<vector<int>>& nums, vector<int>& path){
    int m = nums[0].size();
    vector<int> maxNum(m, 0);
    for(auto p : path){
        for(int i = 0; i < m; ++i){
            maxNum[i] = max(maxNum[i], nums[p][i]);
        }
    }
    int res = INT_MAX;
    for(int i = 0; i < m; ++i){
        res = min(res, maxNum[i]);
    }
    return res;
}

void backtracking(vector<vector<int>>& nums, vector<int> path, int cur, int n, int& res, int k){
    int plen = path.size();
    if(plen == k){
        res = max(res, calculate(nums, path));
        return;
    }
    if(n - cur + plen < k) return;
    for(int i = cur; i < n; ++i){
        path.push_back(i);
        backtracking(nums, path, i + 1, n, res, k);
        path.pop_back();
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> nums(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> nums[i][j];
            }
        }
        int res = 0;
        backtracking(nums, {}, 0, n, res, k);
        cout << res << endl;
    }
}
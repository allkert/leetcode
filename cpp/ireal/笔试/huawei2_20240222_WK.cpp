#include <iostream>
#include <vector>
using namespace std;

int minDistance(vector<vector<int>> GridMap, pair<int, int> start, pair<int, int> end) {
    vector<int> dp(abs(start.second - end.second) + 1, 0);//初始化动归数组
    if(start.first < end.first && start.second < end.second) {
        for(int i = start.first; i <= end.first; i++) {
            for(int j = start.second; j <= end.second; j++) {
                dp[j - start.second] += GridMap[i][j]; 
            }
        }
    }
    else if(start.first > end.first && start.second < end.second) {
        for(int i = start.first; i >= end.first; i--) {
            for(int j = start.second; j <= end.second; j++) {
                dp[j - start.second] += GridMap[i][j]; 
            }
        }
    }
    else if(start.first < end.first && start.second < end.second) {//从终点到起点
        for(int i = end.first; i <= start.first; i++) {
            for(int j = end.second; j <= start.second; j++) {
                dp[j - end.second] += GridMap[i][j]; 
            }
        }
    }
    else {
        for(int i = end.first; i >= start.first; i--) {
            for(int j = end.second; j <= start.second; j++) {
                dp[j - end.second] += GridMap[i][j]; 
            }
        }
    }
    return dp[abs(start.second - end.second)];

}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> GridMap;
    vector<pair<int, int>> Cpos;
    int Clen = 0;
    //初始化网格图
    int temp;
    int S_row, S_col;
    int E_row, E_col;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> temp;
            if(temp == 'S') { //记录起点的位置
                GridMap[i][j] = 0;
                S_row = i;
                S_col = j;
            }
            else if(temp== 'E') { //记录终点的位置//记录检查点的位置
                GridMap[i][j] = 0;
                E_row = i;
                E_col = j;
            }
            else if(temp == 'C') {
                GridMap[i][j] = 0;
                Cpos.push_back(pair<int, int> (i, j));
                Clen++;
            }
            else if(temp == 'B') {
                GridMap[i][j] = INT_MAX;
            }
            else {
                GridMap[i][j] = temp;
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < Clen; i++) {
        ans = min(ans, minDistance(GridMap, pair<int, int> (S_row, S_col), Cpos[i]) + minDistance(GridMap, pair<int, int> (E_row, E_col), Cpos[i]));
    }

    cout << ans << endl;
    return 0;
}
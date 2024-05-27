#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> minDistance(vector<vector<int>> GridMap, pair<int, int> source) {
    int m = GridMap.size();
    int n = GridMap[0].size();
    vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
    distance[source.first][source.second] = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited(m, vector<bool> (n, false));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int min_dis = INT_MAX;
            pair<int, int> min_pos;
            // 找到未访问并且距离source最近的点，那么这个距离一定是最短距离
            for(int x = 0; x < m; x++){
                for(int y = 0; y < n; y++){
                    if(!visited[x][y] && distance[x][y] < min_dis){
                        min_dis = distance[x][y];
                        min_pos = pair<int, int> (x, y);
                    }
                }
            }
            visited[min_pos.first][min_pos.second] = true;
            for(auto dir : directions){
                int x = min_pos.first + dir.first;
                int y = min_pos.second + dir.second;
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]){
                    distance[x][y] = min(distance[x][y], distance[min_pos.first][min_pos.second] + GridMap[x][y]);
                }
            }
    }
    return distance;
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
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> height(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> height[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    function<int(int, int)> dfs = [&](int x, int y){
        if(vis[x][y]) return vis[x][y];
        vis[x][y] = 1;
        for(auto dir : dirs){
            int nextx = x + dir[0];
            int nexty = y + dir[1];
            if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
            if(height[nextx][nexty] >= height[x][y]) continue;
            vis[x][y] = max(dfs(nextx, nexty) + 1, vis[x][y]);
        }
        return vis[x][y];
    };
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dfs(i, j);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            res = max(res, vis[i][j]);
        }
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")
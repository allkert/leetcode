#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int n, m;
    cin >> n >> m;
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push({xs - 1, ys - 1});
    dis[xs-1][ys-1] = 0;
    bool find = false;
    while(!q.empty()){
        if(find) break;
        auto cur = q.front(); q.pop();
        for(auto dir : direction){
            int nextx = cur.first + dir[0];
            int nexty = cur.second + dir[1];
            if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && dis[nextx][nexty] == INT_MAX && grid[nextx][nexty] == '.'){
                dis[nextx][nexty] = dis[cur.first][cur.second] + 1;
                if(nextx == xt - 1 && nexty == yt - 1) find = true;
                q.push({nextx, nexty});
            } 
        }
    }
    if(find) cout << dis[xt - 1][yt - 1] << endl;
    else cout << -1 << endl;
}
// 64 位输出请用 printf("%lld")
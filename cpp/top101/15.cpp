#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nodeNum = 5000;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid = vector<vector<int>>(nodeNum + 1, vector<int>(nodeNum + 1,
                               INT_MAX));
    for (int i = 0; i < m; i++) {
        int x1, x2, co;
        cin >> x1 >> x2 >> co;
        grid[x1][x2] = co;
        grid[x2][x1] = co;
    }
    vector<int> minDis(nodeNum + 1, INT_MAX);
    minDis[1] = 0;
    vector<bool> inTree(nodeNum + 1, false);
    inTree[1] = true;
    for (int i = 1; i <= nodeNum + 1; i++) {
        if (grid[1][i] < minDis[i]) {
            minDis[i] = grid[1][i];
        }
    }

    for (int i = 1; i < nodeNum + 1; i++) {
        int cur = -1, d = INT_MAX;
        for (int j = 1; j <= nodeNum; j++) {
            if (!inTree[j] && minDis[j] < d) {
                cur = j;
                d = minDis[j];
            }
        }
        // cout << cur << d << endl;
        if(cur == -1) break;
        inTree[cur] = true;
        for (int j = 1; j <= nodeNum; j++) {
            if (!inTree[j] && grid[cur][j] != INT_MAX) {
                minDis[j] = min(minDis[j], d + grid[cur][j]);
            }
        }
    }
    if(minDis[n] != INT_MAX) cout << minDis[n] << endl;
    else cout << -1 << endl;
}
// 64 位输出请用 printf("%lld")
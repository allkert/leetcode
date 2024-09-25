#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> path;
    auto g = vector<vector<int>>(n + 1, vector<int>());
    auto inDeg = vector<int>(n + 1, 0);
    int x, y;
    while (cin >> x >> y) {
        inDeg[y]++;
        g[x].push_back(y);
    }
    queue<int> que;
    for(int i = 1; i <= n; i++){
        if(!inDeg[i]){
            que.push(i);
            path.push_back(i);
            inDeg[i] = -1;
        }
    }
    while(!que.empty()){
        auto node = que.front(); que.pop();
        for(auto n : g[node]){
            inDeg[n]--;
            if(inDeg[n] == 0){
                que.push(n);
                path.push_back(n);
            }
        }
    }
    if(path.size() != n) cout << -1 << endl;
    else{
        cout << path[0];
        for(int i = 1; i < n; i++){
            cout << " " << path[i];
        }
    }
}
// 64 位输出请用 printf("%lld")
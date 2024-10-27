#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> canReach(n + 1, vector<int>(m + 1));
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        canReach[a].push_back(b);
        canReach[b].push_back(a);
    }
    vector<int> dis(n + 1, -1);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == n) break;
        for(auto v: canReach[u]){
            if(dis[v] == -1){
                dis[v] = dis[u];
                q.push(v);
            }
            else dis[v] = min(dis[v], dis[u]);
                
        }
        if(u - 1 >= 1){
            if(dis[u - 1] == -1){
                dis[u - 1] = dis[u] + 1;
                q.push(u - 1);
            }
            else dis[u - 1] = min(dis[u - 1], dis[u] + 1);
        }
        if(u + 1 <= n){
            if(dis[u + 1] == -1){
                dis[u + 1] = dis[u] + 1;
                q.push(u + 1);
            }
            else dis[u + 1] = min(dis[u + 1], dis[u] + 1);
        }   
    }
    cout << dis[n] << endl;
}
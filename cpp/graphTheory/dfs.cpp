#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include <array>

using namespace std;

// 547 省份数量
class solution_547{
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int seq){
        visited[seq] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i] && isConnected[seq][i] == 1){
                dfs(isConnected, visited, i);
            }
        }
    }

    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int seq){
        visited[seq] = true;
        queue<int> q;
        q.push(seq);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i = 0; i < isConnected.size(); i++){
                if(!visited[i] && isConnected[cur][i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited = vector<bool>(isConnected.size(), 0);
        int res = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                res++;
                dfs(isConnected, visited, i);
            }
        }
        return res;
    }
};

class Solution_797 {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        dfs(graph, res, path, 0);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path, int cur){
        if(cur == graph.size() - 1){
            res.push_back(path);
            return;
        }
        for(int next : graph[cur]){
            path.push_back(next);
            dfs(graph, res, path, next);
            path.pop_back();
        }
    }
}; 

class Solution_2316 {
private:
    int n = 10e5+5;
    vector<int> father = vector<int>(n, 0);
    void init(){
        for(int i = 0; i < n; i++) father[i] = i;
    }
    int find(int u){
        return u == father[u]? u : father[u] = find(father[u]);
    }

    bool isSame(int u, int v){
        return find(u) == find(v);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u != v) father[v] = u;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
    }
};

int main(){
    array<array<int, 2>, 4>* dirs = new array<array<int, 2>, 4>({1, 0, -1, 0, 0, 1, 0, -1});
    cout << (dirs->at(0))[0];
}
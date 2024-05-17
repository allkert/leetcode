#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include <array>
#include <unordered_set>

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
    int dfs(vector<vector<int>> &graph, int cur, vector<bool>& visited){
        visited[cur] = true;
        int size = 1;
        for(int i = 0; i < graph[cur].size(); i++){
            if(!visited[graph[cur][i]]){
                size += dfs(graph, graph[cur][i], visited);
            }
        }
        return size;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int preTotalNodes = 0;
        long long ans = 0;
        vector<bool> visited = vector<bool>(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int size = dfs(graph, i, visited);
                ans += (long long)size * preTotalNodes;
                preTotalNodes += size;
            }
        }
        return ans;
    }
};

class solution_1319{
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraNum = 0;
        int res = 0;
        int groupNum = 0;
        unordered_set<int> uset;
        init();
        for(auto connect : connections){
            if(isSame(connect[0], connect[1])){
                extraNum++;
            }
            join(connect[0], connect[1]);
        }
        for(int i = 0; i < n; i++){
            int root = find(i);
            if(uset.find(root) == uset.end()){
                groupNum++;
                uset.emplace(root);
            }
        }
        cout << groupNum;
        return extraNum + 1 >= groupNum? groupNum - 1 : -1;
    }
};

int main(){
    solution_1319 s;
    vector<vector<int>> edges({{0, 2}, {0, 5}, {2, 4}, {1, 6}, {4, 5}});
}
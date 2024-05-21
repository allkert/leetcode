#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include <array>
#include <unordered_set>
#include <functional>

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

// 1319. 连通网络的操作次数
class solution_1319_my{
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

// dfs
class solution_1319_ref{
public:
    void dfs(int u, vector<bool>& used, vector<vector<int>>& edges){
        used[u] = true;
        for(int v : edges[u]){
            if(!used[v]) dfs(v, used, edges);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections){
        if(connections.size() < n - 1) return -1;
        vector<vector<int>> edges = vector<vector<int>>(n, vector<int>());
        vector<bool> used = vector<bool>(n, false);
        // 构建edges矩阵
        for(auto connection : connections){
            edges[connection[0]].push_back(connection[1]);
            edges[connection[1]].push_back(connection[0]);
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                dfs(i, used, edges);
                ans++;
            }
        }
        return ans;
    }
};  

// 2492. 两个城市间路径的最小分数
class solution_2492_dfs{
// 一般深搜
// 这道题的实质是把这个图分成多个互相不连通的图，找到这些个子图的各自边的最小权值
private:
    int dfs(vector<vector<int>>& graph, vector<vector<int>>& distance, int cur, vector<bool>& visited){
        visited[cur] = true;
        int ans = INT_MAX;
        for(int i = 0; i < graph[cur].size(); i++){
            ans = min(ans, distance[cur][i]);
            if(!visited[graph[cur][i]]){
                ans = min(ans, dfs(graph, distance, graph[cur][i], visited));
            }
        }
        return ans;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // 建图
        // vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<vector<int>> distance = vector<vector<int>>(n + 1, vector<int>());
        vector<bool> visited(n + 1, false);
        for(auto edge : roads){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            distance[edge[0]].push_back(edge[2]);
            distance[edge[1]].push_back(edge[2]);
        }
        return dfs(graph, distance, 1, visited);
    }
};  

class solution_2492_dju{
private:
    int n = 10e5 + 5;
    // vector<int> father = vector<int>(n, 0);
    // vector<int> father(3, 0);  作为成员变量不可以这样定义！！为什么呢？？
    vector<int> father{vector<int>(n, 0)};
    void init(){
        for(int i = 0; i < n; i++){
            father[i] = i;
        }
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
        if(u != v){
            father[v] = u;
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads){
        init();
        vector<int> minWeight(n + 1, INT_MAX);
        for(auto road : roads){
            minWeight[road[0]] = min(minWeight[road[0]], road[2]);
            minWeight[road[1]] = min(minWeight[road[1]], road[2]);
            join(road[0], road[1]);
        }
        int root = find(1);
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(find(i) == root){
                ans = min(ans, minWeight[i]);
            }
        }
        return ans;
    }
};  
class Solution_2685 {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int& edgeNum, int& nodeNum, int node){
        nodeNum++;
        edgeNum += graph[node].size();
        visited[node] = true;
        for(int i = 0; i < graph[node].size(); i++){
            if(!visited[graph[node][i]]){
                dfs(graph, visited, edgeNum, nodeNum, graph[node][i]);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // 建图
        int ans = 0;
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int edgeNum = 0;
                int nodeNum = 0;
                dfs(graph, visited, edgeNum, nodeNum, i);
                if(nodeNum*(nodeNum - 1) == edgeNum) ans++;
            }
        }
        return ans;
    }
};   

// 有向无环图的拓扑排序
/* 按照一定的顺序访问输出有向无环图的所有节点，每个节点只能输出一次，并且如果一个节点是另一个节点的前驱节点，那么前驱节点一定在前面 
    只有有向无环图才有拓扑排序 */
// 2192. 有向无环图中一个节点的所有祖先
// bfs方法
class Solution_2192_ref_1 {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
        // 节点的祖先集合
        vector<unordered_set<int>> anc(n);
        // 邻接表
        vector<vector<int>> e(n);
        // 入度表
        vector<int> indeg(n);
        for(auto& edge : edges){
            e[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }  
        // bfs
        queue<int> q;
        // 所有入度为0的节点
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int v : e[u]){
                // u是v的直接祖先
                anc[v].insert(u);
                // i是u的所有祖先，所以也即v的所有间接祖先（当然也可能包含一些直接祖先）
                for(int i : anc[u]){
                    anc[v].insert(i);
                }
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            for(int node : anc[i]){
                res[i].push_back(node);
            }
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};  

// 把所有的边反向，然后dfs，能搜到的都是自己的祖先
class solution_2192_reverse_dfs{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges){
        vector<vector<int>> graph(n);
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        for(auto& edge : edges){
            graph[edge[1]].push_back(edge[0]);
        }
        function<void(int)> dfs = [&](int x){
            visited[x] = true;
            for(int y : graph[x]){
                if(!visited[y]) dfs(y);
            }
        };

        for(int i = 0; i < n; i++){
            visited
        }
    }
};


int main(){
    solution_2492_dju s;
    vector<vector<int>> roads({{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}});
    cout << s.minScore(4, roads);
}
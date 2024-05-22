#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include <array>
#include <unordered_set>
#include <functional>
#include <unordered_map>
#include <set>
#include <math.h>

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
            fill(visited.begin(), visited.end(), false);
            dfs(i);
            visited[i] = false;
            for(int j = 0; j < n; j++){
                if(visited[j]) ans[i].push_back(j);
            }
        }
        return ans;
    }
};  

// 924. 尽量减少恶意软件的传播
class solution_924_my{
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int nodeNum = graph.size();
        vector<int> visited(nodeNum);
        int start = 1;
        function<int(int)> dfs = [&](int node) -> int {
            visited[node] = start;
            int areaNum = 1;
            for(int i = 0; i < nodeNum; i++){
                if(!visited[i] && graph[node][i] == 1){
                    areaNum += dfs(i);
                }
            }
            return areaNum;
        };

        // key：区域编号  value：这个区域的节点数量
        unordered_map<int, int> area;
        for(int i = 0; i < nodeNum; i++){
            if(!visited[i]){
                int tempNodeNum = dfs(i);
                area.insert(pair<int, int>(start, tempNodeNum));
                start++;
            }
        }
        int ans = nodeNum;
        int areaNodeNum = 0;


        vector<vector<int>> area_initial(start);
        for(int initialNode : initial){
            area_initial[visited[initialNode]].push_back(initialNode);
        } 


        // 遍历所有区域，找到只包含一个初始感染节点的区域
        for(int i = 1; i < start; i++){
            if (area_initial[i].size() == 1){
                cout << i << endl;
                if(area[i] > areaNodeNum || (area[i] == areaNodeNum && area_initial[i][0] < ans)){
                    areaNodeNum = area[i];
                    ans = area_initial[i][0];
                }
            }
            else if(areaNodeNum == 0){
                for(int a : area_initial[i]){
                    ans = min(ans, a);
                }
            }
        }
        return ans;
    }
};

class solution_924_ref{
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial){
        // use vector to construct a set
        set<int> st(initial.begin(), initial.end());
        vector<int> vis(graph.size());
        int ans = -1, max_size = 0, node_id, size;
        // 状态机
        // -1：初始状态
        // 非负数x：表示第x个节点是唯一一个感染节点
        // -2：表示有多个感染节点
        function<void(int)> dfs = [&](int x){
            vis[x] = 1;
            size++;
            if(node_id != -2 && st.count(x)){
                node_id = node_id == -1? x : -2;
            }
            for(int y = 0; y < graph.size(); y++){
                if(graph[x][y] && !vis[y]){
                    dfs(y);
                }
            }
        };

        for(int x : initial){
            if(vis[x]) continue;
            node_id = -1;
            size = 0;
            dfs(x);
            if(node_id >= 0 && (size > max_size || size == max_size && node_id < ans)){
                ans = node_id;
                max_size = size;
            }
        }
        if(ans >= 0) return ans;
        ans = INT_MAX;
        for(int x : initial){
            if(x < ans) ans = x;
        }
        return ans;
    }
};

class solution_2101{
private:
    void bulidEdges(vector<vector<int>>& bombs, vector<vector<int>>& edges){
        int bombNum = bombs.size();
        // 建图
        for(int i = 0; i < bombs.size(); i++){
            for(int j = 0; j < bombs.size(); j++){
                long delta_x = bombs[i][0] - bombs[j][0];
                long delta_y = bombs[i][1] - bombs[j][1];
                long r = bombs[i][2];
                if(i != j && pow(delta_x, 2) + pow(delta_y, 2) <= r * r){
                    edges[i].push_back(j);
                }
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int size = 0;
        int ans = 0;
        vector<bool> visited(bombs.size(), false);
        vector<vector<int>> edges(bombs.size());
        bulidEdges(bombs, edges);
        function<void(int)> dfs = [&](int x){
            visited[x] = true;
            size++;
            for(auto y : edges[x]){
                if(!visited[y]) dfs(y);
            }
        };
        for(int i = 0; i < bombs.size(); i++){
            size = 0;
            fill(visited.begin(), visited.end(), false);
            dfs(i);
            ans = max(ans, size);
        }
        return ans;
    }
}; 

// 802. 找到最终的安全状态
// 使用多个颜色标记节点的状态
/* 
    0：未访问
    1: 访问过的结点
    2：安全结点
 */
class sloution_802_1{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> dfs = [&](int x) -> bool{
            if(color[x] > 0){
                return color[x] == 2;                                   
            }
            color[x] = 1;
            for(int y : graph[x]){
                if(!dfs(y)) return false;
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dfs(i)) ans.push_back(i);
        }

        return ans;
    }
};  

class solution_802_2{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n = graph.size();
        vector<bool> visited(n);
        vector<int> ans;
        function<bool(int)> dfs = [&](int x) -> bool{
            if(visited[x]) return false;
            visited[x] = true;
            for(int y :)
        };
    }
};

int main(){
    solution_2101 s;
    vector<vector<int>> graph = {{2, 1, 3}, {6, 1, 4}};
    cout << s.maximumDetonation(graph);
}
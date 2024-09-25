#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include <unordered_map>

using namespace std;

class Solution_1557{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
        unordered_set<int> zeroIndegreeSet = unordered_set<int>();
        vector<vector<int>> v = vector<vector<int>>(n, vector<int>());
        vector<int> res;
        for(auto edge : edges){
            zeroIndegreeSet.insert(edge[1]);
        }
        for(int i = 0; i < n; i++){
            if(zeroIndegreeSet.find(i) == zeroIndegreeSet.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};  


class Solution_207{
public:
    bool dfs(int u, vector<int>& vis, vector<vector<int>>& edges){
        vis[u] = 1;
        for(auto& v : edges[u]){
            if(!vis[v]){
                if(!dfs(v, vis, edges)) return false;
            }
            else if(vis[v] == 1) return false;
        }
        vis[u] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges = vector<vector<int>>(numCourses, vector<int>());
        for(auto& p : prerequisites){
            edges[p[1]].push_back(p[0]);
        }
        vector<int> visited = vector<int>(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(!dfs(i, visited, edges)) return false;
            }
        }
        return true;
    }
};  

class Solution_210 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges = vector<vector<int>>(numCourses, vector<int>());
        vector<int> inDeg = vector<int>(numCourses);
        for(auto& p : prerequisites){
            edges[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }
        vector<int> res;
        int learned = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0){
                q.push(i);
                learned++;
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int course = q.front(); q.pop();
            for(int nextCourse : edges[course]){
                inDeg[nextCourse]--;
                if(inDeg[nextCourse] == 0){
                    learned++;
                    q.push(nextCourse);
                    res.push_back(nextCourse);
                }
            }
        }

        if(learned == numCourses) return res;
        return {}; 
    }
};  

class Solution_1462_1{
    // bfs + 拓扑排序
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries){
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for(auto& p : prerequisites){
            indegree[p[1]]++;
            g[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()){
            int course = q.front(); q.pop();
            for(auto& ne : g[course]){
                isPre[course][ne] = true;
                for(int i = 0; i < numCourses; i++){
                    if(isPre[i][course]) isPre[i][ne] = true;
                }
                indegree[ne]--;
                if(!indegree[ne]) q.push(ne);
            }
        }
        vector<bool> res;
        for(auto& query : queries){
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};  

class Solution_1462_2{
// dfs + 拓扑排序
void dfs(vector<vector<int>>& g, vector<vector<bool>>& isPre, vector<bool>& visited, int cur){
    if(visited[cur]) return;
    visited[cur] = true;
    for(int& next : g[cur]){
        dfs(g, isPre, visited, next);
        isPre[cur][next] = true;
        for(int i = 0; i < isPre.size(); i++){
            if(isPre[next][i]) isPre[cur][i] = true;
        }
    }
}
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries){
        vector<vector<bool>> isPre = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> graph = vector<vector<int>>(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        for(vector<int>& pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        for(int i = 0; i < numCourses; i++){
            dfs(graph, isPre, visited, i);
        }
        vector<bool> res;
        for(vector<int>& query : queries){
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }

};

class Solution_2115_1{
// bfs + 拓扑排序
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> table;
        unordered_map<string, int> inDeg;
        int n = recipes.size();
        for(int i = 0; i < n; i++){
            for(auto ingredient : ingredients[i]){
                table[ingredient].push_back(recipes[i]);
                inDeg[recipes[i]]++;
            }
        }
        queue<string> q;
        for(auto supply : supplies){
            q.push(supply);
        }
        vector<string> res;
        while(!q.empty()){
            string cur = q.front(); q.pop();
            for(auto next : table[cur]){
                inDeg[next]--;
                if(!inDeg[next]){
                    q.push(next);
                    res.push_back(next);
                }
            }
        }
        return res;
    }
};

int main(){
    unordered_map<string, int> m;
    string s = "1";
    if(!m["s"]){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
};
# include<vector>

using namespace std;


// 797. 所有可能的路径
class Solution_797{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<vector<int>> res;
        dfs(graph, res, {0}, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path, int cur){
        if(cur == graph.size() - 1){
            res.push_back(path);
            return;
        }
        for(int d : graph[cur]){
            path.push_back(d);
            dfs(graph, res, path, d);
            path.pop_back();
        }
    }
};

// 200. 岛屿数量
class Solution_200_dfs {
private:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; 
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> isSearch(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++)
        }
    }
    void dfs(vector<vector<char>>& grid)
};
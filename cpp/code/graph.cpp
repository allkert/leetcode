#include<vector>
#include <queue>
#include <array>
#include <iostream>

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
            for(int j = 0; j < grid[0].size(); j++){
                if(isSearch[i][j] == 0 && grid[i][j] == '1'){
                    dfs(grid, isSearch, i, j);
                    ans++;
                }
                
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& isSearch, int x, int y){
        // 溢出边界
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        // 已经搜索过
        if(isSearch[x][y]) return;
        // 不是陆地
        if(grid[x][y] == '0') return;
        isSearch[x][y] = 1;
        for(auto d : dir){
            dfs(grid, isSearch, x + d[0], y + d[1]);
        }
    }
};

class Solution_200_bfs {
public:
    array<array<int,2>, 4> dirs = {0, 1, 1, 0, 0, -1, -1, 0};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] != '0'){
                    bfs(grid, visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(array<int, 2> dir : dirs){
                int nextx = cur.first + dir[0];
                int nexty = cur.second + dir[1];
                if(nextx >= 0 && nextx < grid.size() && nexty >= 0 && nexty < grid[0].size() && !visited[nextx][nexty] && grid[nextx][nexty] != '0'){
                    q.push({nextx, nexty});
                    visited[nextx][nexty] = 1;
                }
            }
        }
    }
};

class Solution_695_dfs {
public:
    array<array<int, 2>, 4> dirs = {1, 0, 0, 1, -1, 0, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int thisS = 0;
                    dfs(grid, visited, i, j, thisS);
                    ans = max(ans, thisS);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& S){
        S++;
        visited[x][y] = 1;
        for(auto dir : dirs){
            int nextx = x + dir[0];
            int nexty = y + dir[1];
            if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
            if(visited[nextx][nexty] || grid[nextx][nexty] == 0) continue;
            dfs(grid, visited, nextx, nexty, S);
        }
    }
};

class Solution_695_bfs{
    array<array<int, 2>, 4> dirs = {1, 0, 0, 1, -1, 0, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid){
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    ans = max(ans, bfs(grid, visited, i, j));
                }
            }
        }
        return ans;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y){
        int S = 1;
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(auto dir : dirs){
                int nextx = cur.first + dir[0];
                int nexty = cur.second + dir[1];
                if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
                if(visited[nextx][nexty] || grid[nextx][nexty] == 0) continue;
                visited[nextx][nexty] = 1;
                S++;
                q.push({nextx, nexty});
            }
        }
        return S;
    }
};

class Solution_1020_dfs {
/* 我的思路是正常dfs找所有的岛屿，然后在寻找过程中判断是不是飞地 */
public:
    array<array<int, 2>, 4> dirs = {1, 0, 0, 1, -1, 0, 0, -1};
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int S = 0;
                    visited[i][j] = true;
                    if(dfs(grid, visited, i, j, S)) ans += S;
                }
            }
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& S){
        S++;
        bool ans = true;
        if(x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) ans = false;
        for(auto dir : dirs){
            int nextx = x + dir[0];
            int nexty = y + dir[1];
            if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
            if(visited[nextx][nexty] || grid[nextx][nexty] == 0) continue;
            visited[nextx][nexty] = true;
            if(!dfs(grid, visited, nextx, nexty, S)){
                ans = false;
            }
        }
        return ans;
    }
};

class Solution_1020_bfs{
    array<array<int, 2>, 4> dirs = {1, 0, 0, 1, -1, 0, 0, -1};
public:
    int numEnclaves(vector<vector<int>>& grid){
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int S = 0;
                    visited[i][j] = true;
                    if(bfs(grid, visited, i, j, S)) ans += S;
                }
            }
        }
        return ans;
    }

    bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& S){
        S++;
        queue<pair<int, int>> que;
        que.push({x, y});
        bool tag = true;
        if(x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) tag = false;
        visited[x][y] = true;
        while(!que.empty()){
            pair<int, int> cur = que.front();que.pop();
            for(auto dir : dirs){
                int nextx = cur.first + dir[0], nexty = cur.second + dir[1];
                if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
                if(visited[nextx][nexty] || grid[nextx][nexty] == 0) continue;
                if(nextx == 0 || nexty == 0 || nextx == grid.size() - 1 || nexty == grid[0].size() - 1) tag = false;
                visited[nextx][nexty] = true;
                S++;
                que.push({nextx, nexty});
            }
        }
        return tag;
    }
};

class Solution_1020_dfs_Ref{
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    int count;
    void dfs(vector<vector<int>>& grid, int x, int y){
        // 变成海洋，遍历了的都修改成了海洋，所以不需要visited数组了
        grid[x][y] = 0;
        count++;
        for(auto d : dir){
            int nextx = x + d[0];
            int nexty = y + d[1];
            if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
            if(grid[nextx][nexty] == 0) continue;
            dfs(grid, nextx, nexty); 
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][n-1] == 1) dfs(grid, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1) dfs(grid, 0, i);
            if(grid[m-1][i] == 1) dfs(grid, m-1, i);
        }
        count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) dfs(grid, i, j);
            }
        }
        return count;
    }
};

class Solution_1020_bfs_Ref{
private:
    int dirs[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    int count;
    void bfs(vector<vector<int>>& grid, int x, int y){
        queue<pair<int, int>> que;
        grid[x][y] = 0;
        que.push({x, y});
        count++;
        while(!que.empty()){
            auto cur = que.front(); que.pop();
            for(auto dir : dirs){
                int nextx = cur.first + dir[0], nexty = cur.second + dir[1];
                if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
                if(grid[nextx][nexty] == 0) continue;
                grid[nextx][nexty] = 0;
                que.push({nextx, nexty});
                count++;
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) bfs(grid, i, 0);
            if(grid[i][n-1] == 1) bfs(grid, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1) bfs(grid, 0, i);
            if(grid[m-1][i] == 1) bfs(grid, m-1, i);
        }
        count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) bfs(grid, i, j);
            }
        }
        return count;
    }    
};

class Solution_130_dfs {
public:
    int dirs[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][col-1] == 'O') dfs(board, i, col-1);
        }
        for(int j = 0; j < col; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[row-1][j] == 'O') dfs(board, row - 1, j);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'A') board[i][j] == 'O';
                if(board[i][j] == 'O') board[i][j] == 'X';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int x, int y){
        board[x][y] = 'A';
        for(auto dir : dirs){
            int nextx = x + dir[0], nexty = y + dir[1];
            if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) continue;
            if(board[nextx][nexty] != 'O') continue;
            dfs(board, nextx, nexty);
        }
    }
};

int main(){
    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    Solution_1020_bfs s;
    cout << s.numEnclaves(grid);
}
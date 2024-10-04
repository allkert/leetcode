#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int curx, int cury){
        vis[curx][cury] = 1;
        for(auto dir : dirs){
            int nx = curx + dir[0], ny = cury + dir[1];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !vis[nx][ny] && grid[nx][ny] == '1'){
                dfs(grid, vis, nx, ny);
            }
        }
    }
    int solve(vector<vector<char> >& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    res++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return res;
    }
};
class Solution_994{
// private:
//     int cnt;
//     // dis用来记时间
//     int dis[10][10];
//     int dir_x[4]={0, 1, 0, -1};
//     int dir_y[4]={1, 0, -1, 0};
// public:
//     int orangesRotting(vector<vector<int>>& grid){
//         queue<pair<int, int>> Q;
//         // 所有位置设为-1
//         memset(dis, -1, sizeof(dis));
//         cnt = 0;
//         int m = grid[0].size(), n = grid.size(), ans = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j] == 2){
//                     Q.push(make_pair(i, j));
//                     dis[i][j] = 0;
//                 }
//                 else if(grid[i][j] == 1) cnt += 1;
//             }
//         }

//         while(!Q.empty()){
//             pair<int, int> x = Q.front(); Q.pop();
//             for(int i = 0; i < 4; i++){
//                 int tx = x.first + dir_x[i];
//                 int ty = x.second + dir_y[i];
//                 // 判断是否出界, 或者已经访问过， 或者为空地
//                 if(tx < 0 || tx >= n || ty < 0 || ty >= m || dis[tx][ty] == 0 || grid[tx][ty] == 0) continue;
//                 dis[tx][ty] = dis[x.first][x.second] + 1;
//             }
//         }
//     }
// };
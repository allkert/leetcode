#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> minDistance(vector<vector<int>> GridMap, pair<int, int> source) {
    int m = GridMap.size();
    int n = GridMap[0].size();
    vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
    distance[source.first][source.second] = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited(m, vector<bool> (n, false));
    int count = m * n;
    for(int i = 0; i < count - 1; i++){
        int min_dis = INT_MAX;
        pair<int, int> min_pos;
        // 找到未访问并且距离source最近的点，那么这个距离一定是最短距离
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(!visited[x][y] && distance[x][y] <= min_dis){
                    min_dis = distance[x][y];
                    min_pos = pair<int, int> (x, y);
                }
            }
        }
        visited[min_pos.first][min_pos.second] = true;
        for(auto dir : directions){
            int x = min_pos.first + dir.first;
            int y = min_pos.second + dir.second;
            if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
            if(GridMap[x][y] == -1) continue;
            if(distance[x][y] > distance[min_pos.first][min_pos.second] + GridMap[x][y]){
                distance[x][y] = distance[min_pos.first][min_pos.second] + GridMap[x][y];
            }
        }
        cout << "min_pos: " << min_pos.first << " " << min_pos.second << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << distance[i][j] << '\t' << '\t';
            }
            cout << endl;
        }
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> GridMap(n, vector<int> (m, 0));
    vector<pair<int, int>> Cpos;
    pair<int, int> source;
    pair<int, int> destination;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            string temp;
            cin >> temp;
            if(temp == "S"){
                source = pair<int, int> (i, j);
                GridMap[i][j] = 0;
            }
            else if(temp == "E"){
                destination = pair<int, int> (i, j);
                GridMap[i][j] = 0;
            }
            else if(temp == "B"){
                GridMap[i][j] = -1;
            }
            else if(temp == "C"){
                Cpos.push_back(pair<int, int> (i, j));
                GridMap[i][j] = 0;
            }
            else{
                GridMap[i][j] = stoi(temp);
            }
        }
    }
    int ans = INT_MAX;
    vector<vector<int>> distance1 = minDistance(GridMap, source);
    vector<vector<int>> distance2 = minDistance(GridMap, destination);
    for(auto pos : Cpos){
        ans = min(ans, distance1[pos.first][pos.second] + distance2[pos.first][pos.second]);
    }
    cout << ans << endl;
}
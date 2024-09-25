#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;  



class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>>& grids, int curx, int cury, int& curForksNum, vector<vector<int>>& vis){
        vis[curx][cury] = 1;
        if(grids[curx][cury] == '*'){
            return true;
        }
        int forksNum = 0;
        for(auto dir : dirs){
            int nextx = curx + dir[0];
            int nexty = cury + dir[1];
            if(nextx < 0 || nextx >= grids.size() || nexty < 0 || nexty >= grids[0].size() || grids[nextx][nexty] == 'x' || vis[nextx][nexty] == 1){
                continue;
            }
            else{
                forksNum++;
                if(dfs(grids, nextx, nexty, curForksNum, vis)){
                    return true;
                }
            }
        }
        if (forksNum > 1){
            curForksNum++;
        }
        return false;
    }
};


int main() {
    vector<vector<char>> grids = {}
}
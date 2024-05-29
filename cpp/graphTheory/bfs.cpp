#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<queue>
#include<map>
#include<algorithm>
#include <unordered_map>

using namespace std;

// 1311获取你好友已观看的视频
class soution_1311{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int personNum = friends.size();
        vector<bool> visited(personNum, false);
        map<string, int> count;
        queue<int> que;
        que.push(id);
        visited[id] = true;
        for(int i = 0; i < level; i++){
            count.clear();
            int length = que.size();
            for(int j = 0; j < length; j++){
                int person = que.front(); que.pop();
                for(int f : friends[person]){
                    if(!visited[f]){
                        que.push(f);
                        visited[f] = true;
                        for(string vedio : watchedVideos[f]) count[vedio]++;
                    }
                }
            }
        }
        vector<pair<string, int>> levelVideos;
        for(auto c : count){
            levelVideos.push_back({c.first, c.second});
        }

        sort(levelVideos.begin(), levelVideos.end(), [&](const pair<string, int>& a, const pair<string, int>& b)->bool{return a.second == b.second? a.first < b.first : a.second < b.second;});

        vector<string> ans;
        for(int i = 0; i < levelVideos.size(); i++){
            ans.push_back(levelVideos[i].first);
        }
        return ans;
    }
};

class solution_1311_ref{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level){
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(id);
        visited[id] = true;
        for(int _ = 0; _ < level; _++){
            int length = que.size();
            for(int i = 0; i < length; i++){
                int u = que.front(); que.pop();
                for(int v : friends[u]){
                    if(!visited[v]){
                        que.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
        unordered_map<string, int> freq;
        while(!que.empty()){
            int p = que.front(); que.pop();
            for(const string& video : watchedVideos[p]){
                freq[video]++;
            }
        }
        vector<pair<string, int>> levelVideos(freq.begin(), freq.end());
        sort(levelVideos.begin(), levelVideos.end(), [](const pair<string, int>& a, const pair<string, int>& b){
            return a.second == b.second? a.first < b.first : a.second < b.second;
        });

        vector<string> ans;
        for(auto count : levelVideos){
            ans.push_back(count.first);
        }
        return ans;
    }
}; 

class solution_1129{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        for(auto &e : redEdges){
            next[0][e[0]].push_back(e[1]);
        }
        for(auto &e : blueEdges){
            next[1][e[0]].push_back(e[1]);
        }

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;
        
        dist[0][0] = dist[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});
        while(!q.empty()){
            auto [x, t] = q.front(); q.pop();
            for(auto y : next[1-t][x]){
                if(dist[1-t][y] == INT_MAX){
                    dist[1 - t][y] = dist[t][x] + 1;
                    q.push({y, 1 - t});
                }
            }
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = min(dist[0][i], dist[1][i]);
            if(ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};   

class solution_1129_my{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for(auto &e : redEdges){
            graph[0][e[0]].push_back(e[1]);
        }
        for(auto &e : blueEdges){
            graph[1][e[0]].push_back(e[1]);
        }
        queue<pair<int, bool>> que;
        que.push({0, true});
        que.push({0, false});
        vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
        dis[0][0] = dis[1][0] = 0;
        while(!que.empty()){
            auto [node, isRed] = que.front(); que.pop();
            if(isRed){
                for(auto u : graph[1][node]){
                    if(dis[1][u] == INT_MAX){
                        dis[1][u] = dis[0][node] + 1;
                        que.push({u, false});
                    }
                }
            }
            else{
                for(auto v : graph[0][node]){
                    if(dis[0][v] == INT_MAX){
                        dis[0][v] = dis[1][node] + 1;
                        que.push({v, true});
                    }
                }
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = min(dis[0][i], dis[1][i]);
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }    
};  

class solution_1298 {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
        int n = status.size();
        vector<bool> haskey(n, false);
        vector<bool> hasbox(n, false);
        vector<bool> vis(n, false);
        queue<int> boxs;
        int candy = 0; 
        // 寻找可以打开的盒子，即有钥匙的盒子，但是此时不一定可以直接打开，因为这个盒子可能在其他不能打开的盒子里面
        for(int i = 0; i < n; i++){
            if(status[i]) haskey[i] = true;
        }
        // 找目前可以获取到的盒子
        for(auto b : initialBoxes){
            hasbox[b] = true;
        }
        // 找可以直接打开的盒子
        for(int i = 0; i < n; i++){
            if(hasbox[i] && haskey[i]){
                vis[i] = true;
                boxs.push(i);
            }
        }
        while(!boxs.empty()){
            int box = boxs.front(); boxs.pop();
            // 拿糖果
            candy += candies[box];
            // 拿盒子
            for(auto u : containedBoxes[box]){
                hasbox[u] = true;
                if(haskey[u]){
                    boxs.push(u);
                    vis[u] = true; 
                }
            }
            // 拿钥匙
            for(auto k : keys[box]){
                haskey[k] = true;
                if(hasbox[k] && !vis[k]){
                    boxs.push(k);
                    vis[k] = true;
                }
            }
        }
        return candy;
    }
};

int main(){
    solution_1298 s;
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7,5,4,100};
    vector<vector<int>> keys = {{},{},{1},{}};
    vector<vector<int>> containedBoxes = {{1,2},{3},{},{}};
    vector<int> initialBoxes = {0};
    cout << s.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
}
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

int main(){
    bool T = "ABCD" < "ABCE";
    cout << T;
}
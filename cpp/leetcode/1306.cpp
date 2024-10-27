#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        vector<int> dis(n, -1);
        dis[0] = 0;
        queue<int> q;
        q.emplace(0);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur == n - 1) return dis[n-1];
            if(mp.find(arr[cur]) != mp.end()){
                for(auto nxt : mp[arr[cur]]){
                    if(nxt != cur && dis[nxt] == -1){
                        dis[nxt] = dis[cur] + 1;
                        q.emplace(nxt);
                    }
                }
                mp.erase(arr[cur]);
            }
            if(cur && dis[cur - 1] == -1){
                dis[cur - 1] = dis[cur] + 1;
                q.emplace(cur - 1);
            }
            if(cur < n - 1 && dis[cur + 1] == -1){
                dis[cur + 1] = dis[cur] + 1;
                q.emplace(cur + 1);
            }
        }
        return dis[n-1];
    }
};
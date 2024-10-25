#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int x){
            if(vis[x]) return;
            vis[x] = true;
            if(x - arr[x] >= 0) dfs(x - arr[x]);
            if(x + arr[x] < n) dfs(x + arr[x]); 
        };
        dfs(start);
        for(int i = 0; i < n; ++i){
            if(!arr[i] && vis[i]) return true;
        }
        return false;
    }
};

int main(){
    map<int, vector<int>> mp = {
        {0, {4,2,3,0,3,1,2}},
        {5, {4,2,3,0,3,1,2}},
        {0, {3,0,2,1,2}},
        {2, {3,0,2,1,2}},
        {3, {3,0,2,1,2}},
        {0, {0}},
        {1, {0}},
        {0, {1}},
        {0, {3,0,2,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
        {0, {4,2,3,0,3,1,2}},
    };
    for(auto it : mp){
        cout << it.first << " "  << endl;
    }
}
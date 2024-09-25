#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution1{
public:
    int miniSpanningTree(int n, int m, vector<vector<int>>& cost){
        unordered_set<int> points;
        int res = 0;
        sort(cost.begin(), cost.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        // 加入权值最小的边
        points.insert(cost[0][0]);
        points.insert(cost[0][1]);
        res += cost[0][2];
        while(true){
            if(points.size() == n){
                break;
            }
            for(auto it = cost.begin(); it != cost.end(); it++){
                if((points.find((*it)[0]) != points.end() && points.find((*it)[1]) == points.end()) || (points.find((*it)[1]) == points.end() && points.find((*it)[0]) != points.end())){
                    res += (*it)[2];
                    points.insert((*it)[0]);
                    points.insert((*it)[1]);
                    cost.erase(it);
                    break;
                }
            }
        }
        return res;
    }

};  

// 并查集+kruskal算法
class Solution2{
public:
    int find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }

    void join(vector<int>& parent, int u, int v) {
        int root1 = find(parent, u);
        int root2 = find(parent, v);
        if (root1 != root2) {
            parent[root1] = root2;
        }
    }
    int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
        vector<int> parent(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        sort(cost.begin(), cost.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int res = 0;
        for (auto& c : cost) {
            int root1 = find(parent, c[0]);
            int root2 = find(parent, c[1]);
            if (root1 != root2) {
                join(parent, c[0], c[1]);
                res += c[2];
            }
        }
        return res;
    }
};
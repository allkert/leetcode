#include<iostream>
#include<queue>
#include <unordered_map>

using namespace std; 

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x): val(x), left(nullptr), right(nullptr){}
// };  

// TreeNode* buildTree(vector<vector<int>>& graph, int nodeNum){
//     int nodeVal = 1;
//     TreeNode* root = new TreeNode(nodeVal);
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()){
//         TreeNode* node = q.front(); q.pop();
//         for(int i = 1; i <= nodeNum; i++){
//             if(graph[i].size() == 0) continue;
//             else if
//         }
// }
    
    

int main(){
    int n;
    cin >> n; 
    int u, v;
    vector<vector<int>> edges; // 记得包含vector库，自动包含了
    while(cin >> u >> v){
        edges.push_back({u, v});
    }
    // vector<vector<int>> graph(n + 1, vector<int>());
    // for(auto edge : edges){
    //     graph[edge[0]].push_back(edge[1]);
    // }
    unordered_map<int, int> layer;
    layer.insert({1, 1});
    for(auto edge : edges){
        layer[edge[1]] = layer[edge[0]] + 1;
    }
    int left = 0, right = 0;
    for(auto l : layer){
        if(l.second % 2 == 0) left++;
        else right++;
    }
    cout << left * right - edges.size() << endl;
}
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int m;
    cin >> m;
    vector<int> originTree = vector<int>(m, 0);
    unordered_map<int, int> umap;
    for(int i = 0; i < m; i++){
        cin >> originTree[i];
        umap[originTree[i]]++;
    }
    int n;
    cin >> n;
    vector<int> referTree = vector<int>(n, 0);
    for(int i = 0; i < n; i++){
        cin >> referTree[i];
    }
    int layer = (int)(log2(n)) + 1;
    for(int i = 0; i < layer; i++){
        unordered_map<int, int> originCount;
        unordered_map<int, int> referCount;
        for(int j = pow(2, i) - 1; j < pow(2, i + 1)-1  && j < m; j++){
            originCount[originTree[j]]++;
            if(j < n) referCount[referTree[j]]++;
        }
        for(auto a : referCount){
            if(originCount[a.first] != 0){
                umap[a.first] -= min(originCount[a.first], referCount[a.first]);
            }
        }
    }
    // 从umap中取出来放在vector中
    vector<pair<int, int>> res;
    for(auto a : umap){
        if(a.second != 0) res.push_back(a);
    }
    // 排序，先按照value降序，再按照key降序
    sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });

    for(auto a : res){
        cout << a.first;
    }
    cout << endl;
}
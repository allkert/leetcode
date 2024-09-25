#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    // 输入是一个二维 list，每一列表示一个特征，最后一列表
    // 示标签 label，特征和label都为整数，其中特征取值有三
    // 种:0，1，2，label取值有两种:0，1。
    // 如果某一行只输入1个-1，表示输入结束。
    string line;
    vector<vector<int>> data;
    while(getline(cin, line)){
        vector<int> row;
        for(int i = 0; i < line.size(); i++){
            if(line[i] != ' '){
                row.push_back(line[i] - '0');
            }
        }
        data.push_back(row);
    }
    // 样本数量
    int D = data.size();
    // 特征数量
    int N = data[0].size() - 1;
    // 计算每个特征的信息增益
    vector<float> gains(N, 0);
    
}
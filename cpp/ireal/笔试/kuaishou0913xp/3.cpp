
using namespace std;
// sum(i, j)表示从i到j的和，包括i和j， 请检查是否计算出错
// 给你M条记录, 每条记录有三个整数a, b, c, 表示从a到b的和为c
// 如果当前记录与之前的记录有冲突，输出"BUG Detected" 空格 正确的和
#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <map>

using namespace std; 

void check(vector<map<int, int>> &record, int a, int b, int c){
    bool isRight = true;
    for(int i = 0; i < a; i++){
        if(record[i].find(b) != record[i].end() && record[i].find(a-1) != record[i].end()){
            if(record[i][b] - record[i][a-1] != c){
                isRight = false;
                cout << "BUG Detected " << (record[i][b] - record[i][a-1]) << endl;
                break;
            }
        }
    }
    if(isRight){
        for(int i = a; i < b; i++){
            if(record[a].find(i) != record[a].end() && record[i+1].find(b) != record[i+1].end()){
                if(record[a][i] + record[i+1][b] != c){
                    isRight = false;
                    cout << "BUG Detected " << (record[a][i] + record[i+1][b]) << endl;
                    break;
                }
            }
        }
    }
    if(isRight){
        cout << "Accept" << endl;
        record[a][b] = c;
    }
}


int main() {

    int M;
    cin >> M;
    vector<map<int, int>> record(M);
    vector<int> a(10), b(10), c(10);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 0; i < M; i++){
        check(record, a[i] - 1, b[i] - 1, c[i]);
    }
}
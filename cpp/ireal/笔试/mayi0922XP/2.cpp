#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    // 人数和菜的数量
    int n, m;
    cin >> n >> m;
    long int res = 0;
    // 每个人对每道菜的喜爱程度
    vector<vector<int>> like(n, vector<int>(m));
    // 每道菜的喜爱程度之和
    vector<vector<int>> sumlike(m, vector<int>(2, 0));
    // 记录每道菜是否被选中
    vector<bool> isSelect(m, false);
    for(int i = 0; i < m; i++){
        sumlike[i][0] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> like[i][j];
            if(i != 0){
                sumlike[j][1] += like[i][j];
            }
        }
    }
    // 从大到小排序
    sort(sumlike.begin(), sumlike.end(), [](vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    });
    // 挑选前三个
    for(int i = 0; i < 3; i++){
        isSelect[sumlike[i][0]] = true;
        res = res +  sumlike[i][1] + like[0][sumlike[i][0]];
    }
    // 其余n-1个人每个人点自己最喜欢的菜
    for(int i = 1; i < n; i++){
        int maxlike = 0;
        int maxindex = 0;
        for(int j = 0; j < m; j++){
            if(like[i][j] > maxlike && !isSelect[j]){
                maxlike = like[i][j];
                maxindex = j;
            }
        }
        // 这里这个人最喜欢的菜，每个人的喜爱值都要加
        for(int j = 0; j < n; j++){
            res += like[j][maxindex];
        }
        isSelect[maxindex] = true;
    }
    cout << res << endl;
}
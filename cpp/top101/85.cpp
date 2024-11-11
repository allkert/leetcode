#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> nums[i][j];
        }
    }
    int res = -INT_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            vector<int> line(n, 0);
            for(int k = i; k <= j; ++k){
                for(int l = 0; l < n; ++l){
                    line[l] += nums[k][l];
                }
            }
            int dp = line[0];
            res = max(res, dp);
            for(int k = 1; k < n; ++k){
                dp = max(dp + line[k], line[k]);
                res = max(res, dp);
            }
        }
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    vector<int> dp(m, 0);
    dp[0] = grid[0][0];
    for(int j = 1; j < m; ++j) dp[j] = dp[j-1] + grid[0][j];
    for(int i = 1; i < n; ++i){
        dp[0] += grid[i][0];
        for(int j = 1; j < m; ++j){
            dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
        }
        // for(auto d : dp){
        //     cout << d << ' ';
        // }
        // cout << endl;
    }
    cout << dp[m-1] << endl;
}
// 64 位输出请用 printf("%lld")
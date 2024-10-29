#include <cerrno>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >>n;
    vector<int> prices(n);
    for(int i = 0; i < n; ++i) cin >> prices[i];
    vector<vector<int>> dp(n, vector<int>(5, 0));
    for(int i = 1; i < 5; i += 2){
        dp[0][i] = -prices[0];
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < 5; ++j){
            if(j % 2 == 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
            }
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
        }
    }
    cout << dp[n-1][4] << endl;
}
// 64 位输出请用 printf("%lld")
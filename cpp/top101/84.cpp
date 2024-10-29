#include <cerrno>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    vector<vector<int>> dp(n, vector<int>(2*k+1, 0));
    for (int i = 1; i < 2*k+1; i += 2) {
        dp[0][i] = -prices[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < 2*k+1; ++j) {
            if (j % 2 == 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            } else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
        }
    }
    cout << dp[n - 1][2*k] << endl;
}
// 64 位输出请用 printf("%lld")
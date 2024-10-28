#include <cerrno>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxProfitGreedy(vector<int>& prices){
    int res = 0;
    for(int i = 1; i < prices.size(); ++i){
        if(prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
    }
    return res;
}

int maxProfitGreedyDP(vector<int>& prices){
    int days = prices.size();
    vector<pair<int, int>> dp(days);
    dp[0].first = -prices[0];
    for(int i = 1; i < days; ++i){
        dp[i].first = max(dp[i-1].first, dp[i-1].second - prices[i]);
        dp[i].second = max(dp[i-1].second, dp[i-1].first + prices[i]);
    }
    return dp[days-1].second;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for(int i = 0; i < n; ++i) cin >> prices[i];
    cout << maxProfitGreedyDP(prices) << endl;
}


// 64 位输出请用 printf("%lld")
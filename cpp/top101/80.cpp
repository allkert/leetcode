#include <climits>
#include <iostream>
#include <mutex>
#include <vector>
using namespace std;


// ########1. 动态规划
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        if(dp[i] == INT_MAX) continue;
        for(int j = i + 1; j <= min(n-1, i + nums[i]); ++j){
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    if(dp[n-1] == INT_MAX) cout << -1 << endl;
    else cout << dp[n-1] << endl;
}
// 64 位输出请用 printf("%lld")

// ########2. 贪心算法
// 从前往后遍历，每次到达边界之后，就找最大的下一个边界
#include <climits>
#include <iostream>
#include <mutex>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    int curBound = 0, nextbound = 0;
    int res = 0, i;
    for(i = 0; i < n - 1; ++i){
        nextbound = max(nextbound, i + nums[i]);
        if(i == nextbound) break;
        if(i == curBound){
            res++;
            curBound = nextbound;
        }
    }
    if(i < n - 1) cout << -1 << endl;
    else cout << res << endl;
}
// 64 位输出请用 printf("%lld")
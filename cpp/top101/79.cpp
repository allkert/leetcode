#include <climits>
#include <iostream>
#include <vector>
using namespace std;


// ########1. 动态规划
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; ++i) cin >> nums[i];
//     vector<int> dp(n, -1);
//     dp[0] = nums[0];
//     for(int i = 0; i < n; ++i){
//         if(dp[i] == -1) continue;
//         // cout << i << endl;
//         for(int j = i + 1; j <= min(i + nums[i], n - 1); ++j){
//             dp[j] = max(dp[j], dp[i] + nums[j]);
//         }
//     }
//     cout << dp[n-1] << endl;
// }
// 64 位输出请用 printf("%lld")

// ########2. 贪心算法
// 从后往前遍历，如果当前位置能到达最后一个位置，那么就加上当前位置的值， 因为题目规定这个位置的值一定为非负数
// 假设这个位置前面有位置可以到达最后一个位置，那么它一定可以到达这个位置，所以肯定加上更大
// 最后判断能否到达初始位置，如果不能，输出-1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    int res = 0;
    int reach = n - 1;
    for(int i = n - 1; i >= 0; --i){
        if(i + nums[i] >= reach){
            res += nums[i];
            reach = i;
            // cout << i << endl;
        }
    }
    if(!reach) cout << res << endl;
    else cout << -1 << endl;
}
// 64 位输出请用 printf("%lld")
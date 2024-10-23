// #include <climits>
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> bombs(n);
//     for(int i = 0; i < n; ++i){
//         cin >> bombs[i];
//     }
//     vector<bool> visited(n, false);
//     vector<int> dp(n, 1);
//     int maxBombs = 0;
//     for(int i = 0; i < n; ++i){
//         for(int j = 0; j < i; ++j){
//             if(bombs[i] <= bombs[j]) dp[i] = max(dp[i], dp[j] + 1);
//         }
//         maxBombs = max(maxBombs, dp[i]);
//     }
//     int visNum = 0;
//     int sysNum = 0;
//     while(visNum < n){
//         sysNum++;
//         int prev = INT_MAX;
//         for(int i = 0; i < n; ++i){
//             if(!visited[i] && bombs[i] <= prev){
//                 visited[i] = true;
//                 visNum++;
//                 prev = bombs[i];
//             }
//         }
//     }
//     cout << maxBombs << endl << sysNum << endl;
// }
// // 64 位输出请用 printf("%lld")  

// ===================================================================
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> bombs(n);
    for(int i = 0; i < n; ++i){
        cin >> bombs[i];
    }
    int res1 = 0, res2 = 0;
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(bombs[i] <= bombs[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
            else dp2[i] = max(dp2[i], dp2[j] + 1);
        }
        res1 = max(res1, dp1[i]);
        res2 = max(res2, dp2[i]);
    }
    cout << res1 << endl << res2 << endl;
}
// 64 位输出请用 printf("%lld")
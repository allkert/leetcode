#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            dp[i] += dp[j];
        }
    }
    cout << dp[n] << endl;
}
// 64 位输出请用 printf("%lld")

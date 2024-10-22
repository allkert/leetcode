#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n <= 2) cout << 1 << endl;
    else{
        vector<int> dp = {1, 1, 0};
        for(int i = 2; i < n; i++){
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        cout << dp[2] << endl;
    }
}
// 64 位输出请用 printf("%lld")
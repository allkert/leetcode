#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long dp0 = 1, dp1 = 2;
    for(int i = 2; i <= n; i++){
        long tmp0 = (2 * dp1 + 1);
        long tmp1 = (2 * dp1 + dp0 + 2);
        dp0 = tmp0 % 1000000007;
        dp1 = tmp1 % 1000000007;
    }
    cout << dp0 << ' ' << dp1 << endl;
}
// 64 位输出请用 printf("%lld")
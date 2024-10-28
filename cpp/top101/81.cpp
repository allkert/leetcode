#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for(int i = 0; i < n; ++i) cin >> prices[i];
    int dp0 = -prices[0], dp1 = 0;
    int res = 0;
    for(int i = 1; i < n; ++i){
        dp0 = max(dp0, -prices[i]);
        dp1 = max(dp1, prices[i] + dp0);
        res = max(res, dp1);
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; ++i) cin >> cost[i];
    if(n == 1) return cost[0];
    int dp1 = 0, dp2 = 0, temp;
    for(int i = 2; i <= n; ++i){
        temp = dp2;
        dp2 = min(dp2 + cost[i-1], dp1 + cost[i-2]);
        dp1 = temp;
    }
    cout << dp2 << endl;
}
// 64 位输出请用 printf("%lld")
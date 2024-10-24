#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    int dp1 = 0, dp2 = 0, temp = 0;
    for(int i = 0; i < n; ++i){
        temp = dp2;
        dp2 = max(dp2, dp1 + nums[i]);
        dp1 = temp;
    }
    cout << dp2 << endl;
}
// 64 位输出请用 printf("%lld")
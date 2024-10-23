#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) cin >> height[i];
    int res = INT_MAX;
    for (int div = 0; div <= n; ++div) {
        int lsize = div, rsize = n - div;
        // cout << lsize << ' ' << rsize << endl;
        int max_up = 0, max_down = 0;
        if (lsize) {
            max_up = 1;
            vector<int> dp1(lsize, 1);
            for (int i = 1; i < lsize; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (height[i] > height[j]) {
                        dp1[i] = max(dp1[i], dp1[j] + 1);
                    }
                    max_up = max(max_up, dp1[i]);
                }
            }
        }
        // cout << max_up << endl;
        if (rsize) {
            max_down = 1;
            vector<int> dp2(rsize, 1);
            for (int i = div + 1; i < n; ++i) {
                for (int j = div; j < i; ++j) {
                    if (height[i] < height[j]) {
                        dp2[i - div] = max(dp2[i - div], dp2[j - div] + 1);
                        // cout << i - div << ' ' << dp2[i - div] << endl;
                    }
                }
                max_down = max(max_down, dp2[i - div]);
            }

        }
        // cout << max_down << endl;
        int removeNum =  n - max_down - max_up;
        if (lsize && rsize && height[div] == height[div - 1]) removeNum++;
        // cout << removeNum << endl;
        res = min(res, removeNum);
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")
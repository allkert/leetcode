#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp = 0, res = -INT_MAX;
    int num;
    int maxNum = -INT_MAX;
    for(int i = 0; i < n; ++i){
        cin >> num;
        maxNum = max(maxNum, num);
        dp = max(0, dp + num);
        res = max(res, dp);
    }
    cout << (maxNum < 0? maxNum : res) << endl;
}
// 64 位输出请用 printf("%lld")
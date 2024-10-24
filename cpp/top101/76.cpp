#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n - 1; i >= 0; --i){
        for(int j = i; j < n; ++j){
            if(i == j) dp[i][j] = 1;
            else{
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}
// 64 位输出请用 printf("%lld")
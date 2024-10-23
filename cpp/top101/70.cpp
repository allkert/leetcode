// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, 0);
//     dp[0] = 1;
//     for(int i = 1; i <= n; ++i){
//         for(int j = 0; j < i; ++j){
//             dp[i] += dp[j];
//         }
//     }
//     cout << dp[n] << endl;
// }
// // 64 位输出请用 printf("%lld")

#include<bits/stdtr1c++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n + 1);
		iota(v.begin(), v.begin() + n + 1, 0);
		while (v.size() != 1) {
			for (int j = 0; j < int(v.size()); j++)
				v.erase(v.begin() + j);
		}
		cout << v[0] << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int res = 1;
    int left = 0, right = 0;
    while(right < n){
        while(nums[right] - nums[left] > k) left++;
        right++;
        res = max(res, right - left);
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")
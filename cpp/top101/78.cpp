#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int i;
    for(i = 0; i < n; ++i) cin >> nums[i];
    int max_cover = 0;
    for(i = 0; i < n; ++i){
        max_cover = max(max_cover, i + nums[i]);
        if(i >= max_cover) break;
    }
    cout << (i >= n - 1? "true" : "false") << endl;
    
}
// 64 位输出请用 printf("%lld")
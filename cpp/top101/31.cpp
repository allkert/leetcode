#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    auto time = vector<vector<int>>(n, vector<int>(2));
    for(int i = 0; i < n; ++i){
        cin >> time[i][0] >> time[i][1];
    }
    sort(time.begin(), time.end(), [&](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });
    int end = 0;
    int res = 0;
    for(auto meeting : time){
        // cout << meeting[0] << meeting[1] << endl;
        if(meeting[0] >= end){
            res++;
            end = meeting[1];
        }
        // cout << res << end << endl;
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")
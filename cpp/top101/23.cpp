#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int n){
    if(n == 2 || n == 3) return true;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

void backtracking(vector<int>& nums, int cur, int acc, int& res, set<int>& p){
    if(cur == nums.size()){
        res = min(res, acc);
        return;
    }
    for(int i = 2; i <= nums[cur]; i++){
        if(nums[cur] % i == 0 && isPrime(i) && !p.count(i)){
            p.insert(i);
            backtracking(nums, cur + 1, acc + i, res, p);
            p.erase(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = INT_MAX;
    set<int> p;
    backtracking(nums, 0, 0, res, p);
    res == INT_MAX ? cout << -1 << endl : cout << res << endl;
}
// 64 位输出请用 printf("%lld")
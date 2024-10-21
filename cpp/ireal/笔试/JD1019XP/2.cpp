#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> nums[i];
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 1; i <= n; ++i) {
        if(pq.size() < k) {
            pq.push(nums[i]);
        } else {
            if(nums[i] < pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        cout << (pq.size() == k ? pq.top() : -1) << ' '; 
    }
}
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

// Function to perform BFS and compute the shortest path from a to b
int bfs(int a, int b, const vector<int>& list) {
    queue<pair<int, int>> q; // (current_number, steps)
    unordered_set<int> visited;
    q.push({a, 0});
    visited.insert(a);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == b) {
            return steps;
        }

        // Try flipping each bit
        for (int i = 0; i < 31; ++i) {
            int flipped = current ^ (1 << i);
            if (visited.find(flipped) == visited.end()) {
                visited.insert(flipped);
                q.push({flipped, steps + 1});
            }
        }

        // Try XOR with each number in the list
        for (int num : list) {
            int xored = current ^ num;
            if (visited.find(xored) == visited.end()) {
                visited.insert(xored);
                q.push({xored, steps + 1});
            }
        }
    }

    return -1; // Should never reach here if b is reachable from a
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    int m, z;
    cin >> m >> z;
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    long long result = 0;
    for (int i = 0; i < m; ++i) {
        int a = queries[i].first;
        int b = queries[i].second;
        int steps = bfs(a, b, list);
        if (steps == -1) {
            return 1;
        }
        result = (result + (i + 1) * steps) % MOD;
    }

    cout << result << endl;

    return 0;
}
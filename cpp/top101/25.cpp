#include <climits>
#include <iostream>
#include <vector>
using namespace std;

bool check(int h, int m, string t) {
    int h1 = h / 10, h2 = h % 10;
    int m1 = m / 10, m2 = m % 10;
    if ((h1 == t[0] - '0' || t[0] == '?') && (h2 == t[1] - '0' || t[1] == '?') &&
            (m1 == t[3] - '0' || t[3] == '?') && (m2 == t[4] - '0' ||
                    t[4] == '?')) return true;
    return false;
}

int main() {
    string t1, t2;
    cin >> t1 >> t2;
    vector<int> vec1;
    vector<int> vec2;
    int minT = INT_MAX, maxT = 0;
    for (int i = 0; i < 24 * 60; ++i) {
        int h = i / 60, m = i % 60;
        if (check(h, m, t1)) vec1.push_back(i);
        if (check(h, m, t2)) vec2.push_back(i);
    }
    for (auto v1 : vec1) {
        for (auto v2 : vec2) {
            if (v2 <= v1) continue;
            else {
                maxT = max(maxT, v2 - v1);
                minT = min(minT, v2 - v1);
            }
        }
    }
    cout << minT << ' ' << maxT << endl;
}
// 64 位输出请用 printf("%lld")
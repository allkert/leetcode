#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

// void test(int &a){
//     a = 1;
// }
int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6};
    int value = 4;
    auto it = std::upper_bound(v.begin(), v.end(), value, [](int a, int b) {
        return a < b;  // 自定义的比较逻辑
    });
    cout << *it;
    return 0;
}
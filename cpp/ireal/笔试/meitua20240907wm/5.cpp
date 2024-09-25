#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> cardNums(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> cardNums[i];
    }
}
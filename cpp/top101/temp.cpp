#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> b = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(b.begin(), b.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    for (int i = 0; i < 10; i++) {
        cout << b[i] << " ";
    }
}